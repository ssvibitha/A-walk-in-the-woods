#include <cstdio>
#include <cstdlib>

class StackADT{
    private:
        struct node{
            char data;
            struct node *next;
        };
        struct node *top;
    public:
        StackADT():top(NULL){}
        void push(char val);
        int pop();
        int peek();
        bool isEmpty();
        void display();
};
// Function to check if the stack is empty
bool StackADT::isEmpty(){
    return top == NULL;
}
// Function to push an element into the stack
void StackADT::push(char val){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
// Function to pop an element from the stack
int StackADT::pop(){
    if(top == NULL){
        return '\0';
    }
    struct node *temp = top;
    top = top->next;
    char popped = temp->data;
    free(temp);
    return popped;
}
// Function to peek the top element of the stack
int StackADT::peek(){
    if(top == NULL){
        return '\0';
    }
    return top->data;
}
// Function to display the elements of the stack
void StackADT::display(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Stack: ");
    while(temp != NULL){
        printf("%c ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
