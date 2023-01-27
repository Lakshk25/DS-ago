#include<iostream>
using namespace std;
class queue{
    int rear;
    int front;
    int *arr;
    int size;
    public:
    queue(int size){
        this -> size = size;
        rear = 0;
        front = 0;
        arr = new int[size];
    }
    void enqueue(int data){
        if(rear == size){
            cout<<"queue is full"<<endl;
            return;
        }
        cout<<data<<" pushed"<<endl;
        arr[rear] = data;
        rear++;
    }
    int dequeue(){
        if(front == rear){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        front++;
        if(front == rear){
            front = rear = 0;
        }
        cout<<ans<<" popped"<<endl;
        return ans;
    }
    int isEmpty(){
        if(front == rear){
            return 1;
        }
        return 0;
    }
    int isFull(){
        if(rear == size){
            return 1;
        }
        return 0;
    }
};
int main(){
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.isFull()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(10);

    return 0;
}