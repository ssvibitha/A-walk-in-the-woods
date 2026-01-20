#include "insert_asc.h"    
//Main function 
int main(){
    listADT list1,list2,list3;
    int choice,val;
    while(1){
        printf("Menu\n");
        printf("1. Insert element into list1\n");
        printf("2. Insert element into list2\n");
        printf("3. Merge list1 and list2\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to insert into list1: ");
                scanf("%d",&val);
                list1.insertAsc(val);
                break;
            case 2:
                printf("Enter value to insert into list2: ");
                scanf("%d",&val);
                list2.insertAsc(val);
                break;
            case 3:
                list3.merge(list1,list2);
                break;
            case 4: 
                printf("Displaying list1\n");
                list1.display();
                printf("Displaying list2\n");
                list2.display();
                printf("Displaying merged list\n");
                list3.display();
                break;
            case 5:
                printf("Terminating program...\n");
                return 0;
            default:
                printf("Invalid input..Try again\n");
        }
    }
    return 0;
}