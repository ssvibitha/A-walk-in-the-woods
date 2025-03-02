// Implement QueueADT using arrays
#include<cstdio>
#include<cstdlib>
#define SIZE 5
class QueueADT{
    private:
        char data;
        int front;
        int rear;
        char arr[SIZE];
    public:
        QueueADT():front(-1),rear(-1){}
        void enqueue(char val);
        int dequeue();
        void display();
        int getFront();
        bool isEmpty();
        bool isFull();
};
int main(){
    int choice;
    char popped;
    char val;
    QueueADT queue;
    while(1){
        printf("\nMenu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Enter element to enter into queue: ");
                scanf(" %c",&val);
                queue.enqueue(val);
                break;
            case 2:
                popped = queue.dequeue();
                if (popped == '\0'){
                    printf("Queue is empty..Cannot dequeue\n");
                }else{
                    printf("Dequeued element: %c\n",popped);
                }
                break;
            case 3:
                popped = queue.getFront();
                if(popped == '\0'){
                    printf("Queue is empty.. There is no element at the front of queue\n");
                }else{
                    printf("Element at front of queue: %c\n",popped);
                }
                break;
            case 4:
                queue.display();
                break;
            case 5:
                printf("Terminating program...\n");
                return 0;
            default:
                printf("Invalid choice..Try again\n");
        }
    }
    return 0;
}
// Function to check if array is empty
bool QueueADT::isEmpty(){
    return front == -1;
}
// Function to check if array is full
bool QueueADT::isFull(){
    return rear == SIZE-1;
}
// Function to insert element into queue
void QueueADT::enqueue(char val){
    if (isFull()){
        printf("Queue is full..Elements cannot be inserted into queue\n");
        return;
    }
    if (isEmpty()){
        front = 0;
    }
    arr[++rear] = val; 
}
// Function to delete element from queue
int QueueADT:: dequeue(){
    if(isEmpty()){
        return '\0';
    }
    char popped = arr[front];
    if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
}
// Function to display elements of queue
void QueueADT:: display(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("[");
    for(int i=front;i<=rear;i++){
        printf("%c%s",arr[i],i==rear?"]\n":",");
    }
}
// Function to get front element in queue
int QueueADT:: getFront(){
    if (isEmpty()){
        return '\0';
    }else{
        return arr[front];
    }
}

