// Implement list ADT using circular linked list
#include<cstdio>
#include<cstdlib>
class ListADT{
    private:
        struct node{
            int data;
            struct node*next;
        };
        node*head;
    public:
        ListADT():head(NULL){}
        void insertBeginning(int val);
        void insertEnd(int val);
        void insertPosition(int val,int pos);
        int deleteBeginning();
        int deleteEnd();
        int deletePosition(int pos);
        void display();
        int search(int val);
};
int main(){
    int choice,val,res,deleted,pos;
    ListADT list;
    while(1){
        printf("\nMenu\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter an element to insert at beginning: ");
                scanf("%d",&val);
                list.insertBeginning(val);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d",&val);
                list.insertEnd(val);
                break;
            case 3:
                printf("Enter position to insert: ");
                scanf("%d",&pos);
                printf("Enter element to insert at %d: ",pos);
                scanf("%d",&val);
                list.insertPosition(val,pos);
                break;
            case 4:
                deleted = list.deleteBeginning();
                if(deleted == -1){
                    printf("List is empty\n");
                }else{
                    printf("Deleted element: %d\n",deleted);
                }
                break;
            case 5:
                deleted = list.deleteEnd();
                if(deleted == -1){
                    printf("List is empty\n");
                }else{
                    printf("Deleted element: %d\n",deleted);
                }
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d",&pos);
                deleted = list.deletePosition(pos);
                if(deleted == -1){
                    printf("Position not found\n");
                }else{
                    printf("Deleted element: %d\n",deleted);
                }
                break;
            case 7:
                list.display();
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d",&val);
                res = list.search(val);
                if(res == -1){
                    printf("Element not found\n");
                }else{
                    printf("Element found at position %d\n",res);
                }
                break;
            case 9:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
// Function to insert at beginning
void ListADT::insertBeginning(int val){
    node*newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocation failed...\n");
        return;
    }
    newnode->data = val;
    if(head == NULL){
        newnode->next = newnode;
    }else{
        node*temp = head;
        while(temp->next!= head){
            temp= temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    head = newnode;
}
// Function to insert at end
void ListADT::insertEnd(int val){
    struct node*newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocatio failed\n");
        return;
    }
    newnode->data = val;
    if(head == NULL){
        newnode->next = newnode;
        head= newnode;
    }else{
        node*temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}
// Function to insert element at position 
void ListADT::insertPosition(int val,int pos){
    node*newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = val;
    
    if(pos == 1){
        insertBeginning(val);
        return;
    }
    int count =1;
    node*temp = head;

    while(count<pos && temp->next!= head){
        count ++;
        temp = temp->next;
    }
    if(count<pos-1){
        printf("Position not found\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
// Function to delete from beginning
int ListADT::deleteBeginning(){
    node*temp = head;
    int deleted;
    if(temp == NULL){
        return -1;
    }if(temp->next == head){
        deleted = temp->data;
        head = NULL;
    }else{
        deleted = temp->data;
        while(temp->next!= head){
            temp=temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }
    return deleted;
}
// Function to delete from the end 
int ListADT::deleteEnd(){
    node*temp = head;
    int deleted;
    if(temp == NULL){
        return -1;
    }
    if(temp->next == head){
        deleted= temp->data;
        head = NULL;
    }else{
        while(temp->next->next != head){
            temp = temp->next;
        }
        deleted = temp->next->data;
        temp->next = head;
    }
    return deleted;
}
// Function to delete from a given position
int ListADT::deletePosition(int pos) {
    if (head == NULL) {
        return -1; 
    }
    if (pos == 1) {
        return deleteBeginning();
    }
    
    node* temp = head;
    int count = 1;
    
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }
    
    if (count < pos - 1 || temp->next == head) {
        return -1;
    }
    
    node* del = temp->next;
    int deleted = del->data;
    temp->next = del->next;
    free(del);
    return deleted;
}

// Function to display circular linked list
void ListADT:: display(){
    struct node*temp = head;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    }
    printf("[");
    do{
        printf("%d%s",temp->data,temp->next == head?"]\n":",");
        temp = temp->next;
    }while(temp!=head);
}
// Function to search for an element in circular linked list
int ListADT::search(int val) {
    if (head == NULL) {  
        printf("List is empty\n");
        return -1;
    }
    node* temp = head;
    int pos = 1;
    do {
        if (temp->data == val) {
            return pos; 
        }
        temp = temp->next;
        pos++;
    } while (temp != head); 
    return -1; 
}