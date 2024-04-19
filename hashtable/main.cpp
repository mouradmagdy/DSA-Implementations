#include<iostream>
using namespace std;

#define TABLE_SIZE 128

class LinkedHashEntry{
    int key;
    int value;
    LinkedHashEntry *next;

public:
    LinkedHashEntry(int key,int value){
        this->key=key;
        this->value=value;
        this->next=nullptr;
    }

    int getKey(){
        return key;
    }

    int getValue(){
        return value;
    }

    void setValue(int value){
        this->value=value;
    }
    LinkedHashEntry *getNext(){
        return next;
    }

    void setNext(LinkedHashEntry *next){
        this->next=next;
    }
};

class HashMap {
private:
    LinkedHashEntry **table;

public:
    HashMap() {
        table = new LinkedHashEntry *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    int get(int key) {
        int hash = (key % TABLE_SIZE);
        if (table[hash] == nullptr) {
            return -1;
        } else {
            LinkedHashEntry *entry = table[hash];
            while (entry != nullptr && entry->getKey() != key) {
                entry = entry->getNext();
            }
            if (entry == nullptr) {
                return -1;
            } else {
                return entry->getValue();
            }
        }
    }


    void put(int key, int value) {
        int hash = key % TABLE_SIZE;
        if (table[hash] == nullptr) {
            table[hash] = new LinkedHashEntry(key, value);
        } else {
            LinkedHashEntry *entry = table[hash];
            while (entry != nullptr) {
                entry = entry->getNext();
            }
            if (entry->getKey() == key) {
                entry->setValue(value);
            } else {
                entry->setNext(new LinkedHashEntry(key, value));
            }
        }
    }

    void remove(int key) {
        int hash = key % TABLE_SIZE;
        if (table[hash] != nullptr) {
            LinkedHashEntry *prevEntry = nullptr;
            LinkedHashEntry *entry = table[hash];
            while (entry->getNext() != nullptr && entry->getKey() != key) {
                prevEntry = entry;
                entry = entry->getNext();
            }
            if (entry->getKey() == key) {
                if (prevEntry == nullptr) {
                    LinkedHashEntry *nextEntry = entry->getNext();
                    delete entry;
                    table[hash] = nextEntry;
                } else {
                    prevEntry->setNext(entry->getNext());
                    delete entry;
                }
            }
        }
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                LinkedHashEntry *prevEntry = nullptr;
                LinkedHashEntry *entry = table[i];
                while (entry) {
                    prevEntry = entry;
                    entry = entry->getNext();
                    delete prevEntry;
                }
            }
        }
        delete[] table;
    }

};

int main() {
    HashMap hashMap;

    // Inserting key-value pairs
    hashMap.put(1, 10);
    hashMap.put(2, 20);
    hashMap.put(3, 30);

    // Getting values by keys
    cout << "Value for key 1: " << hashMap.get(1) << endl;  // Output: 10
    cout << "Value for key 2: " << hashMap.get(2) << endl;  // Output: 20
    cout << "Value for key 3: " << hashMap.get(3) << endl;  // Output: 30
    cout << "Value for key 4: " << hashMap.get(4) << endl;  // Output: -1 (not found)

    // Removing a key-value pair
    hashMap.remove(2);

    // Attempt to get the value for the removed key
    cout << "Value for key 2 after removal: " << hashMap.get(2) << endl;  // Output: -1 (not found)

    return 0;
}
