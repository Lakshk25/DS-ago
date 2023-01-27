#include <iostream>
using namespace std;
class cQueue
{
    int size;
    int front;
    int rear;
    int *arr;
    public:
    cQueue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return 1;
        }
        return false;
    }
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "queue is full" << endl;
            return;
        }
        if (rear == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        cout<<data<<" pushed"<<endl;
        arr[rear] = data;
    }
    int dequeue(){
        if(front  == -1){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == size - 1){
            front = 0;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else{
            front++;
        }
        cout<<ans<<" deleted"<<endl;
        return ans;
    }
};
int main()
{
    cQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(10);              
    return 0;
}