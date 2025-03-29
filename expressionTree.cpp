// Construct Expression tree
#include<cstdio>
#include<cstdlib>
#include<stack>
class ExpressionTree{
    private:
        struct node{
            char data;
            node*left;
            node*right;
        };
        node* root;
    public:
        ExpressionTree():root(NULL){}
        ~ExpressionTree(){clearTree(root);}
        bool isOperand(char ch);
        bool isOperator(char ch);
        void constructTree(char *val);
        void inorder(node*curr);
        void inorderfn();
        void preorder(node*curr);
        void preorderfn();
        void postorder(node*curr);
        void postorderfn();
        void clearTree(node* curr);
};
int main(){
    ExpressionTree exp;
    char input[100];
    int choice;
    while(1){
        printf("\n------Expression Tree Menu---------\n");
        printf("1. Enter postfix expression\n");
        printf("2. Construct expression tree\n");
        printf("3. Inorder traversal\n");
        printf("4. Preorder traversal\n");
        printf("5. Postorder traversal\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s",input);
                getchar();
                break;
            case 2:
                exp.constructTree(input);
                break;
            case 3:
                exp.inorderfn();
                break;
            case 4:
                exp.preorderfn();
                break;
            case 5:
                exp.postorderfn();
                break;
            case 6:
                printf("Exiting program..\n");
                return 0;
            default:
                printf("Invalid input..Try again..\n");
        }

    }
    return 0;
}
// Function to free all nodes
void ExpressionTree::clearTree(node* curr) {
    if (curr) {
        clearTree(curr->left);
        clearTree(curr->right);
        free(curr);
    }
}
// Check if character is operand
bool ExpressionTree::isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}
// Check if character is operator
bool ExpressionTree::isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
// Construct expression tree
void ExpressionTree::constructTree(char *val){
    std::stack<node*> st;

    for (int i = 0; val[i] != '\0'; i++) {
        char ch = val[i];
        
        if (ch == ' ') continue;  // Skip spaces

        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = ch;
        newNode->left = newNode->right = NULL;

        if (isOperand(ch)) {
            st.push(newNode);
        } 
        else if (isOperator(ch)) {
            if (st.size() < 2) {
                printf("Invalid postfix expression! Not enough operands for operator %c\n", ch);
                free(newNode);
                while (!st.empty()) {
                    free(st.top());
                    st.pop();
                }
                return;
            }
            newNode->right = st.top(); st.pop();
            newNode->left = st.top(); st.pop();
            st.push(newNode);
        }
        else {
            printf("Invalid character in expression: %c\n", ch);
            free(newNode);
            while (!st.empty()) {
                free(st.top());
                st.pop();
            }
            return;
        }
    }

    if (st.size() != 1) {
        printf("Invalid postfix expression! Stack has %zu elements at end\n", st.size());
        while (!st.empty()) {
            free(st.top());
            st.pop();
        }
        return;
    }
    
    clearTree(root);
    root = st.top();
}
// Perform inorder traversal
void ExpressionTree:: inorder(node* curr){
    if(curr== NULL){
        return;
    }
    inorder(curr->left);
    printf("%c ",curr->data);
    inorder(curr->right);
}
// Helper function to call inorder traversal
void ExpressionTree:: inorderfn(){
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
}

// Perform preorder traversal
void ExpressionTree:: preorder(node* curr){
    if(curr == NULL){
        return;
    }
    printf("%c ",curr->data);
    preorder(curr->left);
    preorder(curr->right);
}
// Helper function to call preorder traversal
void ExpressionTree:: preorderfn(){
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
}

// Perform postorder traversal
void ExpressionTree:: postorder(node* curr){
    if (curr == NULL){
        return;
    }
    postorder(curr->left);
    postorder(curr->right);
    printf("%c ",curr->data);
}
// Helper function to call postorder traversal
void ExpressionTree:: postorderfn(){
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
}