//To perform search operations
#include<cstdlib>
#include<cstdio>
#include "sort.h"

void display_arr(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d%s",arr[i], (i == size-1)?"\n":",");
    }
}
int Binary_search(int *arr,int size,int elt){
    int left =0;
    int right = size -1;
    int mid;
    while(right >= left){
        mid = (left+right)/2;
        if(arr[mid] == elt){
            return mid;
        }else if(arr[mid]< elt){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}
int Linear_search(int *arr,int size,int elt){
    for(int i=0;i<size;i++){
        if(arr[i]== elt){
            return i;
        }
    }
    return -1;
}
int main(){
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);
    int *array = (int*)malloc(size* sizeof(int));
    for(int i=0;i<size;i++){
        printf("Enter element at index %d: ",i);
        scanf("%d",&array[i]);
    }
    printf("Array elements successfully written\n");
    printf("Array\n");
    display_arr(array,size); // Print original array

    int element;
    

int choice;
    while(1){
        printf("Menu\n");
        printf("1. Binary Search\n");
        printf("2. Linear search\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        int status;
        switch(choice){
            case 1:
                printf("Enter element to search in the array: ");
                scanf("%d",&element);

                printf("Performing binary search in array\n");

                Bubble_sort(array,size); //Bubble sort function
                status = Binary_search(array,size,element); //Binary search function

                if(status == -1){
                    printf("Element %d, not found\n",element);
                }else{
                    printf("Element %d, found at index %d\n",element,status);
                }

                break;
            case 2:
                printf("Enter element to search in the array: ");
                scanf("%d",&element);

                printf("Performing linear search in array\n");

                status = Linear_search(array,size,element);//Linear search function 
                if(status == -1){
                    printf("Element %d, not found\n",element);
                }else{
                    printf("Element %d, found at index %d\n",element,status);
                }
                break;
            case 3:
                printf("Terminating program...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;


}