#include<iostream>
using namespace std;

class HashEntry{
private:
    int key;
    int value;

public:
    HashEntry(int key,int value){
        this->key =key;
        this->value=value;
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
};

class DeletedEntry:public HashEntry{
private:
    static DeletedEntry*entry;
    DeletedEntry():HashEntry(-1,-1){}

public:
    static DeletedEntry*getUniqueDeletedEntry(){
        if(!entry){
            entry=new DeletedEntry();
        }
        return entry;

    }
};

DeletedEntry *DeletedEntry::entry=nullptr;

const int TABLE_SIZE=128;

class HashMap {
private:
    HashEntry **table;
public:
    HashMap() {
        table = new HashEntry *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    int get(int key) {
        int hash = key % TABLE_SIZE;
        int initialHash = -1;
        while (hash != initialHash && (table[hash] == DeletedEntry::getUniqueDeletedEntry() ||
                                       table[hash] != nullptr && table[hash]->getKey() != key)) {
            if (initialHash == -1) {
                initialHash = hash;
            }
            hash = (hash + 1) % TABLE_SIZE;
        }
        // found an empty place and my key isn't yet found so it doesn't exist or the table if full if hash==initial hash
        if (table[hash] == nullptr || hash == initialHash) {
            return -1;
        } else {
            return table[hash]->getValue();
        }
    }

    void put(int key, int value) {
        int hash = key % TABLE_SIZE;
        int initialHash = -1;
        int indexOfDeletedEntry = -1;

        while (hash != initialHash && (table[hash] == DeletedEntry::getUniqueDeletedEntry() ||
                                       table[hash] != nullptr && table[hash]->getKey() != key)) {
            if (initialHash = -1) {
                initialHash = hash;
            }
            if (table[hash] == DeletedEntry::getUniqueDeletedEntry())
                indexOfDeletedEntry = hash;

            hash = (hash + 1) % TABLE_SIZE;
        }
        // deleted index was found before exiting and we place the new entry there
        if ((table[hash] == nullptr || hash == initialHash) && indexOfDeletedEntry != -1) {
            table[indexOfDeletedEntry] = new HashEntry(key, value);
        } else if (initialHash != hash) {
            // if the key is already present then update the value
            if (table[hash] != DeletedEntry::getUniqueDeletedEntry() && table[hash] != nullptr &&
                table[hash]->getKey() == key) {
                table[hash]->setValue(value);
            } else {
                // if the key is not present then insert the new entry
                table[hash] = new HashEntry(key, value);
            }
        }

    }
    void remove(int key){
        int hash=key%TABLE_SIZE;
        int initialHash=-1;
        while(hash!=initialHash&&(table[hash]!=nullptr&&table[hash]==DeletedEntry::getUniqueDeletedEntry()&&table[hash]->getKey()!=key)){
            if(initialHash==-1)initialHash=hash;

            hash=(hash+1)%TABLE_SIZE;
        }
        if(hash!=initialHash&&table[hash]!=nullptr){
            delete table[hash];
            table[hash]=DeletedEntry::getUniqueDeletedEntry();
        }
    }

    ~HashMap(){
        for(int i=0;i<TABLE_SIZE;i++){
            if(table[i]!=nullptr&&table[i]!=DeletedEntry::getUniqueDeletedEntry()){
                delete table[i];
            }
        }
        delete[] table;

    }


};



int main(){
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
