#include<cstdio>
#include<cstdlib>
#define capacity 100
class Heap{
    private:
        int count;
        int*arr;
    public:
        Heap(){
            count =0;
            arr = (int*)malloc(capacity*sizeof(int));
        }
        int leftChild(int index);
        int rightChild(int index);
        void insert(int data);
        void percolateDown(int index);
        int DeleteMax();
        int GetMax();
        void display();
        bool search(int num);
        ~Heap() {
            free(arr);
        }
};
int main() {
    Heap h;
    int choice;
    int value;
    int popped;

    while (true) {
        printf("\n--------Max Heap Menu-------\n");
        printf("1. Insert element\n");
        printf("2. Remove max element\n");
        printf("3. Sort using heap sort\n");
        printf("4. Search for element\n");
        printf("5. Display heap\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                h.insert(value);
                break;
            case 2:
                popped =h.DeleteMax();
                if (popped!= -1) {
                    printf("Removed element: %d\n", popped);
                }
                break;
            // case 3:
            //     h.heapSort();
                
            //     h.display();
            //     break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &value);
                if (h.search(value)) {
                    printf("%d found in the heap.\n", value);
                } else {
                    printf("%d not found in the heap.\n", value);
                }
                break;
            case 5:
                h.display();
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
// Function to get maximum element
int Heap:: GetMax(){
    if (count == 0){
        return -1;
    }
    return arr[0];
}
// Function to determine left child
int Heap::leftChild(int index){
    int left = 2*index+1;
    if(left>=count) return -1;
    return left;
}
// Function to determine right child
int Heap::rightChild(int index){
    int right = 2*index+2;
    if(right>=count) return -1;
    return right;
}
// Function to perform heapify
void Heap::percolateDown(int index){
    int left,right,max,temp;
    left = leftChild(index);
    right = rightChild(index);
    if(left!= -1 && arr[left]>arr[index]){
        max = left;
    }else{
        max = index;
    }
    if(right!= -1 && arr[right]>arr[max]){
        max = right;
    }
    if(max!= index){
        temp = arr[index];
        arr[index]=arr[max];
        arr[max]=temp;
        percolateDown(max);

    }
}
// Function to delete max element
int Heap::DeleteMax(){
    int data;
    if (count==0){
        return -1;
    }
    data = arr[0];
    arr[0]=arr[count-1];
    count--;
    percolateDown(0);
    return data;
}
// Function to insert new element
void Heap::insert(int data){
    int index;
    if(count==capacity){
        printf("Array full...Cannot insert elements anymore.\n");
        return;
    }
    count++;
    index = count-1;
    while(index>0 && data> arr[(index-1)/2]){
        arr[index]=arr[(index-1)/2];
        index =(index-1)/2;
    }
    arr[index]=data;
}
// Function to display elements
void Heap::display(){
    for(int i=0;i<count;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
// Function to search for an element
bool Heap::search(int num) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}