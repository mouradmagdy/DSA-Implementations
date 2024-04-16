#include <iostream>
#include <stack>
using namespace std;

#define MAX_SIZE 1000
class Stack{
    int top;
    int a[MAX_SIZE];

public:
    Stack(){
        top=-1;
    }

    bool push(int x){
        if(top>=MAX_SIZE){
            cout<<"Stack overflow";
            return false;
        }
        else{
            top++;
            a[top]=x;
            cout<<x<<" pushed into stack"<<endl;
        }
    }

    bool pop(){
        if(top<0){
            cout<<"Stack underflow"<<endl;
            return false;
        }
        else{
            top--;
        }
    }

    int peek(){
        if(top<0){
            cout<<"Stack is empty"<<endl;
        }
        else{
            return a[top];
        }
    }

    bool empty(){
        return top<0;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}
