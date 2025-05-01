// Implement priority queue adt using heap
#include <cstdio>
#include <cstdlib>
#define MAX_SIZE 100

class maxHeap {
private:
    int heapArray[MAX_SIZE];
    int currSize;

public:
    maxHeap() : currSize(0) {}
    void swap(int &num1, int &num2);
    bool search(int num);
    void display();
    void heapifyUp(int index);
    void heapifyDown(int index);
    bool insert(int value);
    bool removeMax(int &value);
    void heapSort();
};


int main() {
    maxHeap h;
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
                if (h.removeMax(popped)) {
                    printf("Removed element: %d\n", popped);
                }
                break;
            case 3:
                h.heapSort();
                
                h.display();
                break;
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
// Function to swap two elements
void maxHeap::swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
// Function to perform search operation
bool maxHeap::search(int num) {
    for (int i = 0; i < currSize; i++) {
        if (heapArray[i] == num) {
            return true;
        }
    }
    return false;
}
// Function to display the heap array
void maxHeap::display() {
    if (currSize == 0) {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap contents: ");
    for (int i = 0; i < currSize; i++) {
        printf("%d ", heapArray[i]);
    }
    printf("\n");
}
// Function to perform heapify up
void maxHeap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heapArray[index] > heapArray[parent]) {
        swap(heapArray[index], heapArray[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}
// Function to perform heapify down
void maxHeap::heapifyDown(int index) {
    int leftChild, rightChild, maxIndex;
    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        maxIndex = index;

        if (leftChild < currSize && heapArray[leftChild] > heapArray[maxIndex]) {
            maxIndex = leftChild;
        }

        if (rightChild < currSize && heapArray[rightChild] > heapArray[maxIndex]) {
            maxIndex = rightChild;
        }

        if (maxIndex == index) {
            break;
        }

        swap(heapArray[index], heapArray[maxIndex]);
        index = maxIndex;
    }
}
// Function to insert an element
bool maxHeap::insert(int value) {
    if (currSize >= MAX_SIZE) {
        printf("Heap is full. Cannot insert more elements.\n");
        return false;
    }

    heapArray[currSize] = value;
    heapifyUp(currSize);
    currSize++;
    printf("Element %d inserted successfully.\n", value);
    return true;
}
// Function to remove element
bool maxHeap::removeMax(int &value) {
    if (currSize <= 0) {
        printf("Heap is empty. Cannot remove.\n");
        return false;
    }

    value = heapArray[0];
    heapArray[0] = heapArray[currSize - 1];
    currSize--;
    heapifyDown(0);
    return true;
}
// Function to perform heap sort
void maxHeap::heapSort() {
    if (currSize <= 1) return;
    printf("Heap sorted in descending order and restored.\n");
    int originalSize = currSize;

    for (int i = originalSize - 1; i > 0; i--) {
        swap(heapArray[0], heapArray[i]);
        currSize--;
        heapifyDown(0);
    }

    currSize = originalSize;

    for (int i = currSize / 2 - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}
