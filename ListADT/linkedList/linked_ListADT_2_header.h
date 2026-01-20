#include<cstdio>
#include<cstdlib>

class listADT{
    private:
        struct linked{
            int data;
            struct linked*next;
        };
        linked *head;

        linked* getHead() const {
            return head;
        }
    public:
        listADT():head(NULL){}
        void insertAsc(int val);
        void merge(const listADT &list1,const listADT &list2);
        void display();
};

//function to insert elements in ascending order
void listADT::insertAsc(int val){
    linked*newnode = (linked*)malloc(sizeof(linked));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL){
       head = newnode; 
    }else{
        linked*temp = head;
        linked*prev = NULL;
        while(temp!=NULL &&temp->data<val){
            prev= temp;
            temp = temp->next;
        }
        if(prev == NULL){
            newnode->next = head;
            head = newnode;
        }
        else{
            prev->next = newnode;
            newnode->next = temp;
        }
    }
}
// function to merge two lists
void listADT::merge(const listADT &list1, const listADT &list2) {

    linked* current1 = list1.getHead();
    linked* current2 = list2.getHead();

    while (current1 && current2) {
        if (current1->data <= current2->data) {
            this->insertAsc(current1->data);
            current1 = current1->next;
        } else {
            this->insertAsc(current2->data);
            current2 = current2->next;
        }
    }

    while (current1) {
        this->insertAsc(current1->data);
        current1 = current1->next;
    }

    while (current2) {
        this->insertAsc(current2->data);
        current2 = current2->next;
    }
}

//function to display elements in the list
void listADT::display(){
    linked*temp = head;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d%s",temp->data,temp->next==NULL?"\n":", ");
        temp = temp->next;
    }
}
