#include "deque.h"
#include<iostream>
using namespace std;
My_Deque::My_Deque(){
    front=rear= nullptr;
    size=0;
}

int My_Deque::end() {
    if(size!=0){
        return rear->val;
    }
    else
        return -1;
}

void My_Deque::push_back(int element) {
    Node *newNode = new Node;
    newNode->val = element;
    //if deque is empty
    if (rear == nullptr) {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        front = rear = newNode;
        size++;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        newNode->next = nullptr;
        rear = newNode;
        size++;
    }
}

void My_Deque::clear() {
    if(front!= nullptr) {
        Node *current = front;
        while (current!= nullptr){
            front=front->next;
            delete current;
            current=front;
        }
    }
    front=rear= nullptr;
    size=0;
}

void My_Deque::print() {
    Node*current=front;
    while(current!= nullptr){
        cout<<current->val<<" ";
        current=current->next;
    }
    cout<<endl;
}

int My_Deque::get_size() {
    return size;
}

void My_Deque::push_front(int element) {
    Node*newNode=new Node;
    newNode->val=element;
    newNode->next= nullptr;
    newNode->prev= nullptr;
    if(front== nullptr){
        front=rear=newNode;
    }
    else{
        newNode->next=front;
        front->prev=newNode;
        front=newNode;
    }
    size++;
}

int My_Deque::begin() {
    if(size!=0){
        return front->val;
    }
    else
        return -1;
}

int My_Deque::pop_back() {
    int x;
    if(rear== nullptr)
        return -1;
    else if(size==1){
        x=front->val;
        delete front;
        front=rear= nullptr;
        size--;
        return x;
    }
    else{
        Node*temp=rear;
        rear=rear->prev;
        rear->next= nullptr;
         x=temp->val;
        delete temp;
        size--;
        return x;
    }

}

int My_Deque::pop_front() {
    int x;
    if(front== nullptr){
        return -1;
    }
    else if(size==1){
        x=front->val;
        delete front;
        front=rear= nullptr;
        size--;
        return x;
    }
    else{
        Node*temp=front;
        front=front->next;
        front->prev= nullptr;
        x=temp->val;
        delete temp;
        size--;
        return x;

    }
}
My_Deque::~My_Deque() {
    delete front;
    delete rear;
}

std::vector<int> My_Deque::toVector() {
    vector<int>convert;
    Node*current=front;
   while(current!= nullptr){
       convert.push_back(current->val);
       current=current->next;
   }
   convert.resize(size);
   delete current;
    return convert;
}
