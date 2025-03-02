// Implement StackADT using array
#include <cstdio>
#include <cstdlib>
#define SIZE 5
class StackADT{
    private:
        int top;
        char arr[SIZE];
    public:
        StackADT():top(-1){}
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
    if(top == SIZE-1){
        printf("Stack is full\n");
        return;
    }
    top++;
    arr[top] = val;
}
// Function to pop an element from the stack
int StackADT :: pop(){
    if(top ==-1){
        return '\0';
    }else{
        int popped= arr[top];
        top--;
        return popped;
    }
}
// Function to peek the top element of the stack
int StackADT::peek(){
    if(top == -1){
        return '\0';
    }else{
        return arr[top];
    }
}
// Function to display the elements of the stack
void StackADT::display(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("[");
    for(int i=0;i<=top;i++){
        printf("%c%s",arr[i],i==top?"]\n":",");
    }
}