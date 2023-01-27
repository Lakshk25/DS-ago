#include<iostream>
using namespace std;
class stack{
    public:
        int top;
        int size;
        int *arr;
        stack(int size){
            top = -1;
            this -> size = size;
            arr = new int(size);
        }
    void push(int elem){
        if(top < size - 1){
            top++;
            arr[top] = elem;
            cout<<elem<<" is pushed in stack"<<endl;
        }
        else{
            cout<<"Stack is full"<<endl;
        }
    }
    void pop(){
        if(top >= 0){
            cout<<arr[top]<<" popped"<<endl;
            top--;
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }
    void peek(){
        if(top >= 0){
            cout<<"peek is "<<arr[top]<<endl;
        }
    }
    int isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }
    int isFull(){
        if(top == size - 1){
            return true;
        }
        return false;
    }
};
int main(){
    stack s(5);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    cout<<s.isFull()<<endl;
    // s.push(10);
    // s.peek();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.isEmpty()<<endl;
    // s.pop();
    return 0;
}