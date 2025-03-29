// Implememt TreeADT using integer binary search tree
#include<cstdio>
#include<cstdlib>
class TreeADT{
    private:
        struct node{
            int data;
            node*left;
            node*right;
        };
        node*root;
    public:
        TreeADT():root(NULL){}
        void insertNode(node *&curr,int val);
        void insertfn (int val);
        void inorderTraversal(node*curr);
        void inorder();
        void preorderTraversal(node*curr);
        void preorder();
        void postorderTraversal(node*curr);
        void postorder();
        bool search(node*curr,int val);
        void searchfn(int val);
};
int main(){
    TreeADT tree;
    int val;
    int choice;
    while(1){
        printf("\n------Binary Search Menu------\n");
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
                printf("Enter an element to insert: ");
                scanf("%d",&val);
                tree.insertfn(val);
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
                printf("Enter an element to search: ");
                scanf("%d",&val);
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
void TreeADT::insertNode(node *&curr,int val){
    if(curr == NULL){
        node*newnode = (node*)malloc(sizeof(node));
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;
        curr = newnode;
        return;
    }else if(curr->data > val){
        insertNode(curr->left,val);
    }else{
        insertNode(curr->right,val);
    }
}
// Funciton to call the recursive function to insert node
void TreeADT::insertfn(int val){
    insertNode(root,val);
}
// Function to perform inorder traversal
void TreeADT::inorderTraversal(node* curr) {
    if (curr == NULL) {
        return;
    }
    inorderTraversal(curr->left);
    printf("%d ", curr->data);
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
    printf("%d ",curr->data);
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
    printf("%d ",curr->data);
}
// Function to call the postorder traversal function
void TreeADT :: postorder(){
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
}
// Function to perform search in binary tree
bool TreeADT:: search(node*curr,int val){
    if(curr== NULL){
        return false ;
    }
    if(curr->data == val){
        return true;
    }else if(curr->data > val){
        return search(curr->left,val);
    }else{
        return search(curr->right,val);
    }
}
// Function to call search function
void TreeADT::searchfn(int val){
    if (search(root,val)){
        printf("%d found in the tree.\n", val);
    }
    else{
        printf("%d not found in the tree.\n", val);
    }
}