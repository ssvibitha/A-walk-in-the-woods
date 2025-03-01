#include <cstdio>
#include <cstring>
#include <cctype>
#include "stack_ll.h"

#define MAX 100 

class ExpressionConverter {
private:
    char infix[MAX];   
    char postfix[MAX];

    int precedence(char op);
    bool isOperator(char ch);
public:
    void getInfix();
    void convertInfixToPostfix();
    void evaluatePostfix();
};

int main() {
    ExpressionConverter converter;
    int choice;

    while (1) {
        printf("\nMenu\n");
        printf("1. Enter Infix Expression\n");
        printf("2. Convert Infix to Postfix\n");
        printf("3. Evaluate Postfix Expression\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                converter.getInfix();
                break;
            case 2:
                converter.convertInfixToPostfix();
                break;
            case 3:
                converter.evaluatePostfix();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to return the precedence of an operator
int ExpressionConverter::precedence(char op) {
    if (op == '=') return 1;
    if (op == '+' || op == '-') return 2;
    if (op == '*' || op == '/' || op == '%') return 3;
    return 0;
}
// Function to check if a character is an operator
bool ExpressionConverter::isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=');
}

// Function to get the infix expression from the user
void ExpressionConverter::getInfix() {
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; 
}
// Function to convert infix expression to postfix expression
void ExpressionConverter::convertInfixToPostfix() {
    StackADT stack;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {  
            postfix[j++] = ch;
        } 
        else if (ch == '(') {
            stack.push(ch);
        } 
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix[j++] = stack.pop();
            }
            stack.pop(); 
        } 
        else if (isOperator(ch)) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix[j++] = stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix[j++] = stack.pop();
    }
    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}
// Function to evaluate the postfix expression
void ExpressionConverter::evaluatePostfix() {
    StackADT stack;
    int variables[26] = {0};

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) { 
            stack.push(ch - '0');
        } 
        else if (isalpha(ch)) { 
            if (variables[ch - 'a'] == 0) { 
                printf("Enter value for %c: ", ch);
                scanf("%d", &variables[ch - 'a']);
            }
            stack.push(variables[ch - 'a']);
        } 
        else { 
            int val2 = stack.pop();
            int val1 = stack.pop();

            switch (ch) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
                case '%': stack.push(val1 % val2); break;
                case '=': 
                    if (val1 >= 0 && val1 < 26) { 
                        variables[val1] = val2;
                        stack.push(val2);
                    } else {
                        printf("Invalid assignment\n");
                    }
                    break;
            }
        }
    }

    printf("Evaluation Result: %d\n", stack.pop());
}
