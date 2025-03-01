// Implement StackADT using linked list
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
        void display();
};
int main(){
    int choice;
    char val,popped;
    StackADT stack;
    while(1){
        printf("\nMenu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter an element to push: ");
                scanf(" %c",&val);
                stack.push(val);
                stack.display();
                break;
            case 2:
                popped = stack.pop();
                if(popped == '\0'){
                    printf("Stack is empty\n");
                }else{
                    printf("Popped element: %c\n",popped);
                }
                break;
            case 3:
                popped = stack.peek();
                if(popped == '\0'){
                    printf("Stack is empty\n");
                }else{
                    printf("Top element: %c\n",popped);
                }
                break;
            case 4:
                stack.display();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
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
