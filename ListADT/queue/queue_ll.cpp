// Implement QueueADT using linked list
#include<cstdio>
#include<cstdlib>
class QueueADT{
    private:
        struct node{
            int data;
            struct node *next;
        };
        struct node*head;
    public:
        QueueADT(): head(NULL){}
        void enqueue(int val);
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
// Function to insert element into queue
void QueueADT::enqueue(int val){
    node*newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocation failed...\n");
        return;
    }
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL){
        head = newnode;
    }else{
        node*temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
// Function to delete element from queue
int QueueADT::dequeue(){
    if(head == NULL){
        return -1;
    }
    node*temp = head;
    int popped = temp->data;
    head = head->next;
    free(temp);
    return popped;
}
// Function to display elements of queue
int QueueADT::peek(){
    if (head == NULL){
        return -1;
    }
    return head->data;
}
// Function to peek front element
void QueueADT::display(){
    if(head == NULL){
        printf("Queue is empty...\n");
        return;
    }
    node*temp = head;
    printf("[");
    while(temp!= NULL){
        printf("%d%s",temp->data,temp->next == NULL ?"]\n":",");
        temp = temp->next;
    }
}