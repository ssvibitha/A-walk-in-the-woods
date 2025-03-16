// Implement QueueADT using Circular Queue using arrays
#include<cstdio>
#define SIZE 5
class QueueADT{
    private:
        int front;
        int rear;
        int arr[SIZE];
    public:
        QueueADT():front(-1),rear(-1){}
        void enqueue(int val);
        bool isEmpty();
        bool isFull();
        int dequeue();
        int peek();
        void display();
};
int main(){
    int choice;
    int popped;
    int val;
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
                scanf("%d",&val);
                queue.enqueue(val);
                break;
            case 2:
                popped = queue.dequeue();
                if (popped == -1){
                    printf("Queue is empty..Cannot dequeue\n");
                }else{
                    printf("Dequeued element: %d\n",popped);
                }
                break;
            case 3:
                popped = queue.peek();
                if(popped == -1){
                    printf("Queue is empty.. There is no element at the front of queue\n");
                }else{
                    printf("Element at front of queue: %d\n",popped);
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
    return (rear+1)%SIZE == front;
}
// Function to insert element into queue
void QueueADT::enqueue(int val){
    if (isFull()){
        printf("Queue is full..Elements cannot be inserted into queue\n");
        return;
    }
    if (isEmpty()){
        front = rear = 0;
    }else{
        rear = (rear+1)%SIZE;
    }
    arr[rear] = val;
}
// Function to delete element from queue
int QueueADT:: dequeue(){
    if(isEmpty()){
        return -1;
    }
    int popped = arr[front];
    if(front== rear){
        front = rear = -1;
    }else{
        front = (front+1)%SIZE;
    }
    return popped;
}
// Function to get front element in queue
int QueueADT:: peek(){
    if (isEmpty()){
        return -1;
    }else{
        return arr[front];
    }
}
// Function to display elements of queue
void QueueADT::display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("[");
    int i = front;
    while (true) {
        printf("%d", arr[i]);
        if (i == rear) break;
        printf(", ");
        i = (i + 1) % SIZE; 
    }
    printf("]\n");
}
