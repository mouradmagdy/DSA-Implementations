#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node*head;

public:
    LinkedList(){
        head=nullptr;
    }

    void insert(int value){
        Node*newNode=new Node(value);
        if(head==nullptr){
            head=newNode;
        }
        else{
            Node*curr=head;
            while(curr->next){
                curr=curr->next;
            }
            curr->next=newNode;
        }
    }

    void display(){
        Node*curr=head;
        while(curr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    void deleteNode(int value){
        if(!head)return;
        if(head->data==value){
            Node*temp=head;
            head=head->next;
            delete temp;
        }
        else{
            Node*curr=head;
            while(curr->next){
                if(curr->next->data==value){
                    Node*temp=curr->next;
                    curr->next=curr->next->next;
                    delete temp;
                    return;
                }
                curr=curr->next;
            }
            if(!curr->next){
                cout<<"Value not found"<<endl;
                return;
            }
        }
    }
};


int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.display();
    list.deleteNode(3);
    list.display();
    list.deleteNode(1);
    list.display();
    list.deleteNode(5);
    list.display();

    return 0;
}
