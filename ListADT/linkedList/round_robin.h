// Round Robin Scheduling Header file
#include<cstdio>
#include<cstdlib>
class RoundRobin{
    private:
        struct process{
            int time;
            struct process*next;
        };
        process*head;
    public:
        RoundRobin():head(NULL){}
        void insertProcess(int time);
        void executeProcess(int fixed_time);
        void display();
        void deleteBeginning();

};
// Function to insert process
void RoundRobin::insertProcess(int time){
    process *newnode = (process*)malloc(sizeof(process));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newnode->time = time;
    if(head == NULL){
        newnode->next = newnode;
        head = newnode;
    }else{
        process*temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}
// Function to execute process
void RoundRobin::executeProcess(int fixed_time){
    if(head == NULL){
        printf("All the processes have been executed\n");
        return;
    }
    int rem_time = head->time - fixed_time;
    deleteBeginning();
    if(rem_time>0){
        insertProcess(rem_time);
    }
}
// Function to display circular linked list
void RoundRobin::display(){
    process*temp = head;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    }
    printf("[");
    do{
        printf("%d%s",temp->time,temp->next == head?"]\n":",");
        temp = temp->next;
    }while(temp!=head);
}
// Function to delete at beginning
void RoundRobin::deleteBeginning() {
    if(head == NULL){  
        return;
    }

    process* temp = head;

    if(head->next == head){ 
        free(head);
        head = NULL;
    }else{
        process* last = head;
        while (last->next != head) { 
            last = last->next;
        }
        last->next = head->next; 
        head = head->next;       
        free(temp);            
    }
}
