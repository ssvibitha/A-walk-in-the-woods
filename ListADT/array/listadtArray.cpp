//List ADT using arrays
#include<cstdio>
#define SIZE_ARR 5
class LISTADT{
    private:
        int arr[SIZE_ARR];
        int size =0;
    public:
        void insertBeginning(int val);
        void insertEnd(int val);
        void insertPos(int val,int pos);
        bool deleteBeginning(int &deleted);
        bool deleteEnd(int &deleted);
        bool deletePos(int pos,int &deleted);
        void display();
        int search(int target);
        void reverse(int start,int end);
        void rotate(int k);
};
int main(){
    LISTADT list;
    int choice;
    int val;
    int pos;
    int k;
    int status;int deleted;
    while(1){
        printf("Menu\n");
        printf("1. Insert beginning\n");
        printf("2. Insert end\n");
        printf("3. Insert position\n");
        printf("4. Delete beginning\n");
        printf("5. Delete end\n");
        printf("6. Delete position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Rotate\n");
        printf("10. Exit\n");

        printf("Enter choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d",&val);
                list.insertBeginning(val);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d",&val);
                list.insertEnd(val);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d",&val);
                printf("Enter position of element(Position 1 indicates index 0):");
                scanf("%d",&pos);
                list.insertPos(val,pos);
                break;
            case 4:
                if(list.deleteBeginning(deleted)){
                    printf("%d\n",deleted); 
                }
                break;
            case 5:
                if(list.deleteEnd(deleted)){
                    printf("%d\n",deleted);
                }
                break;
            case 6:
                printf("Enter position to delete element: ");
                scanf("%d",&pos);
                if(list.deletePos(pos,deleted)){
                    printf("%d\n",deleted);
                }
                break;
            case 7:
                printf("Enter element to search in array: ");
                scanf("%d",&val);
                status = list.search(val);
                if(status == -1){
                    printf("Element %d not found in array\n",val);
                }else if (status == -2){
                    printf("List is empty...Element not found\n");
                }else{
                    printf("Elemnet %d found at index %d",val,status);
                }
                break;
            case 8:
                list.display();
                break;
            case 9:
                printf("Enter number of times to rotate an array:");
                scanf("%d",&k);
                list.rotate(k);
                list.display();
                break;
            case 10:
                printf("Terminating program....\n");
                return 0;
            default:
                printf("Invalid input...Try again\n");
        }
    }
}
void LISTADT:: display(){
    if(size == 0){
        printf("[]\n");
        return;
    }
    printf("[");
    for(int i =0;i<size;i++){
        printf("%d%s",arr[i], i== size-1 ? "]\n":",");
    }
}
void LISTADT:: insertBeginning(int val){
    if(size >= SIZE_ARR){
        printf("Array is full...Element cannot be inserted!!\n");
        return;
    }
    for(int i = size;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]= val;
    size++;
}
void LISTADT:: insertEnd(int val){
    if(size >= SIZE_ARR){
        printf("Array is full...Element cannot be inserted!!\n");
        return;
    }
    arr[size] = val;
    size++;
}
void LISTADT:: insertPos(int val,int pos){
    if(size >= SIZE_ARR){
        printf("Array is full...Element cannot be inserted!!\n");
        return;
    }
    if(pos<1 and pos >size){
        printf("Invalid position\n");
        return;
    }
    for(int i = size;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]= val;
    size++;
}

bool LISTADT:: deleteBeginning(int &deleted){
    if(size == 0){
        printf("List is empty...Cannot delete\n");
        return false;
    }
    deleted = arr[0];
    for(int i =0;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    size--;
    return true;
}
bool LISTADT:: deleteEnd(int &deleted){
    if(size == 0){
        printf("List is empty...Cannot delete\n");
        return false;
    }
    deleted = arr[size-1];
    size--;
    return true;
}
bool LISTADT:: deletePos(int pos, int &deleted){
    if(size == 0){
        printf("List is empty...Cannot delete\n");
        return false;
    }
    if(pos<1 || pos >size){
        printf("Invalid position\n");
        return false;
    }
    deleted = arr[pos-1];
    for(int i = pos-1; i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    return true;
}
void LISTADT:: reverse(int start,int end){
    
    while(start <= end){
        int temp = arr[start];
        arr[start]= arr[end];
        arr[end]= temp;
        start++;
        end--;
    }
}
void LISTADT:: rotate(int k){
    if(size == 0){
        printf("List is empty...Cannot rotate\n");
        return;
    }
    k = k%size;
    reverse(0,size-1);
    reverse(0,k-1);
    reverse(k,size-1);
}
int LISTADT::search(int target){
    if(size == 0){
        return -2;
    }
    for(int i =0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}