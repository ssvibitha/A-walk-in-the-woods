// Implement round robin scheduling using circular linked list
#include "round_robin.h"
int main(){
    int choice,time,deleted,fixed_time;
    RoundRobin list;
    printf("Enter fixed time for each process: ");
    scanf("%d",&fixed_time);
    while(1){
        printf("\nMenu\n");
        printf("1. Insert process\n");
        printf("2. Execute process\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter time for process: ");
                scanf("%d",&time);
                printf("\nProcess Queue\n");
                list.insertProcess(time);

                list.display();
                break;
            case 2:
                list.executeProcess(fixed_time);
                printf("\nProcess Queue\n");
                list.display();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        
        }
    }
    return 0;
}
