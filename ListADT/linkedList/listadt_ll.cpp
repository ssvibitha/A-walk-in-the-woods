//Implement list adt using singly linked list
#include<cstdio>
#include<cstdlib>
class linkedList{
    private:
        struct linked{
            int num;
            struct linked*next;
        };
        linked *head;
    public:
        linkedList() : head(NULL){}
        void insertBeginning(int val);
        void insertEnd(int val);
        void insertPosition(int pos, int val);
        int deleteBeginning();
        int deleteEnd();
        int deletePosition(int pos); 
        int search(int val);
        void display();
        void displayReverse();
        void reverseLink();
};
int main(){
    int choice;
    int val,pos,result,deleted;
    linkedList list;
    while(1){
        printf("Menu\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Display reverse\n");
        printf("10. Reverse link\n");
        printf("11. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                printf("Enter value to insert at beginning:");
                scanf("%d",&val);
                list.insertBeginning(val);//Insert element at beginning
                //list.display();
                break;
            case 2: 
                printf("Enter value to insert at end:");
                scanf("%d",&val);
                list.insertEnd(val);//Insert element at end
                break;
            case 3:
                printf("Enter positon to add element: ");
                scanf("%d",&pos);
                printf("Enter value to insert at position:");
                scanf("%d",&val);
                list.insertPosition(pos,val);//Insert element at a position
                break;
            case 4: 
                deleted = list.deleteBeginning();//Delete element from beginning
                if(deleted != -1){
                    printf("Deleted element:%d\n",deleted);//Display deleted element
                }
                break;
            case 5: 
                deleted = list.deleteEnd();//Delete from the end
                if(deleted != -1){
                    printf("Deleted element: %d\n",deleted);//Display deleted element  
                }
                break;
            case 6: 
                printf("Enter positon to delete element: ");
                scanf("%d",&pos);
                deleted = list.deletePosition(pos);//Delete element from position
                if(deleted != -1){
                    printf("%d",deleted);//Display deleted element
                }
                break;
            case 7:
                printf("Enter element to be searched in linked list: ");
                scanf("%d",&val);
                result = list.search(val);//Search for an element
                if(result == -1){
                    printf("Element not found\n");
                }else if (result!= -2){
                    printf("Element found at index: %d",result);
                }
                break;
            case 8: 
                list.display();//Display linked list
                break;
            case 9:
                list.displayReverse();//Display reversed linked list
                break;
            case 10: 
                list.reverseLink();//Reverse the linked list
                //list.display();
                break;
            case 11: 
                printf("Terminating program...\n");
                return 0;
            default: 
                printf("Invalid input... Try again\n");
        }
    }
    return 0;
}
void linkedList ::insertBeginning(int val){//Insert at beginning
    linked* newnode = (linked*)malloc(sizeof(linked));
    if(newnode == NULL){
        printf("Memory allocation failed....\n");
        return;
    }
    newnode ->num = val;
    newnode->next = head;
    head= newnode;
}
void linkedList ::insertEnd(int val){//Insert at end
    linked* newnode = (linked*)malloc(sizeof(linked));
    if(newnode == NULL){
        printf("Memory allocation failed....\n");
        return;
    }
    newnode->num = val;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }else{
        linked *temp = head;
        while(temp->next != NULL){
            temp  = temp->next;
        }
        temp->next = newnode;
    }
}
void linkedList ::insertPosition(int pos, int val){//Insert at position
    linked* newnode = (linked*)malloc(sizeof(linked));
    if(newnode == NULL){
        printf("Memory allocation failed....\n");
        return;
    }
    newnode->num = val;
    newnode->next = NULL;
    if(pos == 1){
        newnode->next = head;
        head = newnode;
        return;
    }
    int count = 1;
    linked*temp =head;
    while(temp!= NULL && count !=pos-1){
        count ++;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position is out of bounds...\n");
        free(newnode);
        return;
    }
    temp->next = newnode->next;
    temp->next = newnode;
}
int linkedList ::deleteBeginning(){//Delete at beginning
    linked *nodeToDelete= head;
    if(nodeToDelete == NULL){
        printf("List is empty...Deletion at beginning not possible\n");
        return -1;
    }
    int deleted = head->num;
    head = head->next;
    free(nodeToDelete);
    return deleted;
}
int linkedList :: deleteEnd(){//Delete at end
    if(head == NULL){
        printf("List is empty...Deletion at end not possible\n");
        return -1;
    }
    int deleted;
    if(head->next == NULL){
        deleted  = head->num;
        free(head);
        head = NULL;
        return deleted;
    }
    linked *temp = head;
    while(temp->next!= NULL && temp->next->next != NULL){
        temp = temp->next;
    }
    deleted = temp->next->num;
    free(temp->next);
    temp->next = NULL;
    return deleted;
}
int linkedList :: deletePosition(int pos){//Delete at position
    int deleted;
    if(head == NULL){
        printf("List is empty...Deletion at position not possible\n");
        return -1;
    }
    if(pos==1){
        deleted  = head->num;
        linked *temp = head;
        head = head->next;
        free(temp);
        return deleted;

    }
    linked *temp = head;
    int count =1;
    while(temp!= NULL && count != pos-1){
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds...\n");
        return -1; 
    }
    deleted = temp->next->num;
    linked*toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    return deleted;
}
int linkedList :: search(int val){//Search
    if(head == NULL){
        printf("List is empty...Searching is not possible\n");
        return -2;
    }
    int count = 1;
    linked *temp = head;
    while(temp != NULL && temp->num != val){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        return -1;
    }else{
        return count-1;
    }
}
void linkedList :: display(){//Display
    linked *temp = head;
    if(temp == NULL){
        printf("List is empty..\n");
        return;
    }
    printf("[");
    while(temp != NULL){
        printf("%d%s",temp->num, temp->next==NULL?"]\n":",");
        temp=temp->next;
    }
}
void linkedList :: displayReverse(){//Display reverse
    linked* temp = head;
    int count = 0;
    int arr[100];  
    while (temp != NULL) {
        arr[count++] = temp->num;
        temp = temp->next;
    }
    printf("[");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d%s", arr[i], i == 0 ? "]\n" : ", ");
    }
}
void linkedList :: reverseLink(){//Reverse link

    linked* prev = NULL;
    linked* current = head;
    linked* tail = NULL;

    while (current != NULL) {
        tail = current->next;  
        current->next = prev; 
        prev = current;        
        current = tail;        
    }
    head = prev; 
}