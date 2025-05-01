#include<cstdio>
#include<cstdlib>
class ListADT{
    private:
        struct node{
            int data;
            struct node *next;
            struct node *prev;
        };
        struct node *head;
        struct node*tail;
    public:
        ListADT():head(NULL),tail(NULL){}
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
    newnode->next = head;
    newnode->prev = NULL;
    if(head!=NULL){
        head->prev = newnode;
    }else{
        tail = newnode;
    }
    head = newnode;
}
// Function to insert at end
void ListADT::insertEnd(int val){
    node*newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocation failed...\n");
        return;
    }
    newnode->data = val;
    newnode->next = NULL;
    if(tail!= NULL){
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }else{
        head = tail = newnode;
    }
}
// Function to insert at position
void ListADT::insertPosition(int val,int pos){
    node*newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocation failed...\n");
        return;
    }
    newnode->data = val;
    if(pos == 1){
        insertBeginning(val);
        return;
    }
    node*temp = head;
    int count = 1;
    while(count<pos-1 && temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        printf("Position not found\n");
        free(newnode);
        return;
    }else{
        newnode->next = temp->next;
        newnode->prev = temp;
        if(temp->next!=NULL){
            temp->next->prev = newnode;
        }else{
            tail = newnode;
        }
        temp->next = newnode;
    }
}
//Function to delete from beginning
int ListADT::deleteBeginning(){
    if(head == NULL){
        return -1;
    }
    node*temp = head;
    int deleted = temp->data;
    if(head == tail){
        head = tail = NULL;
    }else{
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
    return deleted;
}
// Function to delete from end
int ListADT::deleteEnd(){
    if(tail == NULL){
        return -1;
    }
    node*temp = tail;
    int deleted = temp->data;
    if(head == tail){
        head = tail = NULL;
    }else{
        tail = tail->prev;
        tail->next= NULL;
    }
    free(temp);
    return deleted;
}
// Function to delete from position
int ListADT::deletePosition(int pos){
    if(pos<1){
        return -1;
    }
    node*temp = head;
    int count = 1;
    while(count<pos && temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        return -1;
    }else{
        if(temp->prev != NULL){
            temp->prev->next = temp->next;
        }else{
            head = temp->next;
        }
        if(temp->next != NULL){
            temp->next->prev = temp->prev;
        }else{
            tail = temp->prev;
        }
        int deleted = temp->data;
        free(temp);
        return deleted;
    }
}
// Function to display linked list
void ListADT::display(){
    node*temp = head;
    node*last = NULL;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    }
    printf("Forward traversal\n");
    printf("[");
    while(temp!=NULL){
        printf("%d%s",temp->data,temp->next == NULL?"]\n":",");
        last = temp;
        temp = temp->next;
    }
    temp = last;
    printf("Backward traversal\n");
    printf("[");
    while(temp!=NULL){
        printf("%d%s",temp->data,temp->prev == NULL?"]\n":",");
        temp = temp->prev;
    }
}
// Function to search an element
int ListADT::search(int val){
    node*temp = head;
    if(temp == NULL){
        printf("List is empty\n");
        return -1;
    }else{
        int pos = 1;
        while(temp!=NULL){
            if (temp->data == val){
                return pos;
            }else{
                pos++;
                temp = temp->next;
            }
        }
    }
    return -1;
}