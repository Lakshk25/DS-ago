#include <iostream>
using namespace std;
class kQueue
{
private:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpace;

public:
    kQueue(int K, int S)
    {
        arr = new int[S];
        front = new int[K];
        rear = new int[K];
        next = new int[S];
        for (int i = 0; i < S; i++)
        {
            next[i] = i + 1;
        }
        next[S - 1] = -1;
        for (int i = 0; i < K; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        freeSpace = 0;
    }
    void enqueue(int data, int q)
    {
        if (freeSpace == -1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        int index = freeSpace;
        freeSpace = next[index];
        if (front[q - 1] == -1)
        {
            front[q - 1] = index;
        }
        else
        {
            next[rear[q - 1]] = index;
            next[index] = -1;
            rear[q - 1] = index;
        }
            arr[index] = data;
            cout<<data<<" is added"<<endl;
    }
    int deque(int q){
        if(front[q-1] == -1){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int index = front[q-1];
        front[q-1] = next[index];
        next[index] = freeSpace;
        freeSpace = index;
        cout<<arr[index]<<" is popped"<<endl;
        return arr[index];
    }
};
int main()
{
    kQueue q(3 , 6);
    q.enqueue(1 , 1);
    q.enqueue(2 , 1);
    q.enqueue(3 , 2);
    q.enqueue(4 , 1);
    q.deque(2);
    q.deque(1);
    return 0;
}