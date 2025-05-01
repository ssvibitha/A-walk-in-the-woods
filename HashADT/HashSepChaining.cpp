// Implement Hash table using Separate Chaining
#include <cstdio>
#include <list>

using namespace std;

class HashTable {
private:
    int table_size;
    list<int>* table;

public:
    HashTable(int size){
        table_size = size;
        table = new list<int>[table_size];
    }
    int Hashfn(int key);
    void insert(int key);
    int search(int key);
    bool remove(int key);
    void display();
    ~HashTable() {
        delete[] table;
    }
};

int main(){
    int size,key,choice,deleted;
    printf("Enter size of the Hash Table: ");
    scanf("%d", &size);
    HashTable ht(size);
    while(1){
        printf("\n----HashTable----\n");
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
                if (ht.remove(key))
                    printf("Key deleted successfully.\n");
                else
                    printf("Key not found. Deletion failed.\n");
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
    return key % table_size;
}
//Function to insert an element
void HashTable::insert(int key){
    int index = Hashfn(key);
    table[index].push_back(key);
}
// Function to search for an element
int HashTable::search(int key){
    int index = Hashfn(key);
    for (int x : table[index]) {
        if (x == key) {
            return index;
        }
    }
    return -1;
}
// Function to remove an element from hash table
bool HashTable::remove(int key){
    int index = Hashfn(key);
    if (search(key) == -1){
        return false;
    }
    table[index].remove(key);
    return true;
}
// Function to display hash table
void HashTable::display(){
    printf("Hash Table:\n");
    for (int i = 0; i < table_size; i++) {
        printf("Table [%d] : ", i);
        for (int key : table[i]) {
            printf("%d -> ", key);
        }
        printf("NULL\n");
    }
}