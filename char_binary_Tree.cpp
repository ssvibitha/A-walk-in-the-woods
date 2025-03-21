// Implememt TreeADT using character binary tree
#include<cstdio>
#include<cstdlib>
#include<queue>
class TreeADT{
    private:
        struct node{
            char data;
            node*left;
            node*right;
        };
        node*root;
    public:
        TreeADT():root(NULL){}
        void insertNode(char val);
        void inorderTraversal(node*curr);
        void inorder();
        void preorderTraversal(node*curr);
        void preorder();
        void postorderTraversal(node*curr);
        void postorder();
        bool search(node*curr,char val);
        void searchfn(char val);
};

int main(){
    TreeADT tree;
    char val;
    int choice;
    while(1){
        printf("\n------TreeADT Menu------\n");
        printf("1. Insert\n");
        printf("2. Inorder traversal\n");
        printf("3. Preorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter a character to insert: ");
                scanf(" %c",&val);
                tree.insertNode(val);
                break;
            case 2:
                tree.inorder();
                break;
            case 3:
                tree.preorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                printf("Enter a character to search: ");
                scanf(" %c",&val);
                tree.searchfn(val);
                
                break;
            case 6:
                printf("Terminating program...\n");
                return 0;
            default:
                printf("Invalid input..Try again\n");
        }
    }
}
// Function to insert node into binary tree
void TreeADT::insertNode(char val){
    node* newnode =(node*)malloc(sizeof(node));
    if (!newnode) {
        printf("Memory allocation failed..\n");
        return;
    }
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        root = newnode;
    }else {
        std::queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            else {
                curr->left = newnode;
                return;
            }
            if (curr->right != NULL)
                q.push(curr->right);
            else {
                curr->right = newnode;
                return;
            }
        }
    }
}
// Function to perform inorder traversal
void TreeADT::inorderTraversal(node* curr) {
    if (curr == NULL) {
        return;
    }
    inorderTraversal(curr->left);
    printf("%c ", curr->data);
    inorderTraversal(curr->right);
}
// Function to call the inorder traversal function
void TreeADT :: inorder(){
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
}
// Function to perform preorder traversal
void TreeADT::preorderTraversal(node*curr){
    if(curr == NULL){
        return;
    }
    printf("%c ",curr->data);
    preorderTraversal(curr->left);
    preorderTraversal(curr->right);
}
// Function to call the preorder traversal function
void TreeADT :: preorder(){
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");
}
// Funtion to perform postoder traversal
void TreeADT::postorderTraversal(node*curr){
    if(curr == NULL){
        return;
    }
    postorderTraversal(curr->left);
    postorderTraversal(curr->right);
    printf("%c ",curr->data);
}
// Function to call the postorder traversal function
void TreeADT :: postorder(){
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
}
// Function to perform search in binary tree
bool TreeADT:: search(node*curr,char val){
    if(curr== NULL){
        return false ;
    }
    if(curr->data == val){
        return true;
    }
    return search(curr->left,val)||search(curr->right,val);
}
// Function to call search function
void TreeADT::searchfn(char val){
    if (search(root,val)){
        printf("%c found in the tree.\n", val);
    }
    else{
        printf("%c not found in the tree.\n", val);
    }
}