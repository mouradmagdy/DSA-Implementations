#include<iostream>
using namespace std;

class Trie {
private:
    Trie *children[26] = {};
    bool isWord = false;

public:
    Trie() = default;

    void insert(string const &word) {
        Trie *cur = this;
        for (char c: word) {
            c -= 'a';
            if (cur->children[c] == nullptr) {
                cur->children[c] = new Trie();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;

    }

    bool search(string const &word) {
        Trie *cur = this;
        for (char c: word) {
            c -= 'a';
            if (cur->children[c] == nullptr)return false;
            cur = cur->children[c];
        }
        return cur->isWord;
    }

    bool startsWith(string const &prefix) {
        Trie *cur = this;
        for (char c: prefix) {
            c -= 'a';
            if (cur->children[c] == nullptr)return false;
            cur = cur->children[c];
        }
        return true;
    }
};

int main(void){
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    obj->insert("app");
    cout << obj->search("app") << endl;
    return 0;
}

