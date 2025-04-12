// Implement Hash table using linear probing
#include<cstdio>
#include<cstdlib>
#define EMPTY -1
#define DELETED -2
class HashTable{
    private:
        int* table;
        int size;
        int elementCount;
    public:
        HashTable(int n){
            size = n;
            elementCount = 0;
            table=(int*)malloc(n*sizeof(int));
            for(int i =0;i<n;i++){
                table[i] = EMPTY;
            }
        }
        int Hashfn(int key);
        void insert(int key);
        int search(int key);
        bool remove(int key);
        void display();
};
int main(){
    int size,key,choice,deleted;
    printf("Enter size of the Hash Table: ");
    scanf("%d", &size);
    HashTable ht(size);
    while(1){
        printf("----HashTable----\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                ht.insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                {
                    int pos = ht.search(key);
                    if (pos == -1)
                        printf("Key not found.\n");
                    else
                        printf("Key found at index %d.\n", pos);
                }
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                ht.remove(key);
                break;
            case 4: 
                ht.display();
                break;
            case 5:
                printf("Terminating program..\n");
                return 0;
            default: 
                printf("Invalid input...Try again\n");
        }
    }
}
// HashFunction
int HashTable::Hashfn(int key){
    return key%size;
}
//Function to insert an element
void HashTable::insert(int key){
    if(elementCount == size){
        printf("Hash table is full..\n");
        return;
    }
    int index = Hashfn(key);
    int i =0;
    int start = index;
    while(table[index] != EMPTY && table[index]!= DELETED){
        if(table[index] == key){
            printf("Duplicate Key! Insertion Failed.\n");
            return;
        }
        index = (index + 1) % size;
        if (index == start) break;
    }
    table[index] = key;
    elementCount++;
    printf("Key %d inserted at index %d.\n", key, index);
    
}
// Function to search for an element
int HashTable::search(int key) {
    int index = Hashfn(key);
    int startIndex = index;

    while (table[index] != EMPTY) {
        if (table[index] == key) {
            return index;
        }
        index = (index + 1) % size;
        if (index == startIndex) break;
    }
    return -1;
}
// Function to remove an element from hash table
 bool HashTable:: remove(int key) {
    int index = search(key);
    if (index == -1) {
        printf("Key %d not found. Cannot delete.\n", key);
        return false;
    }
    table[index] = DELETED;
    elementCount--;
    printf("Key %d deleted from index %d.\n", key, index);
    return true;
}
// Function to display hash table
void HashTable:: display() {
    printf("Hash Table:\n");
    for (int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        if (table[i] == EMPTY)
            printf("EMPTY\n");
        else if (table[i] == DELETED)
            printf("DELETED\n");
        else
            printf("%d\n", table[i]);
    }
}