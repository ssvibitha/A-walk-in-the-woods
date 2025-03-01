#include <cstdio>
#include "stack_ll.h" 

bool isBalanced(const char *str);
int main() {
    int choice;
    char str[100]; 

    while (true) {
        printf("\nMenu:\n");
        printf("1. Check Balance\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string of parentheses: ");
                scanf("%s", str);
                if (isBalanced(str)) {
                    printf("Balanced\n");
                } else {
                    printf("Not Balanced\n");
                }
                break;

            case 2:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
// Function to check if parentheses are balanced using Stack class
bool isBalanced(const char *str) {
    StackADT stk;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            stk.push('(');
        } else if (str[i] == ')') {
            if (stk.isEmpty()) return false;
            stk.pop();
        }
    }
    return stk.isEmpty();
}