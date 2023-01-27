#include <iostream>
using namespace std;
class Deque
{
    int size;
    int *arr;
    int front;
    int rear;

public:
    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return 1;
        }
        return false;
    }
    void pushFront(int data)
    {
        if (isFull())
        {
            cout << "queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        cout << data << " pushed" << endl;
        arr[front] = data;
    }
    void pushRear(int data)
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
        cout << data << " pushed" << endl;
        arr[rear] = data;
    }
    int popRear()
    {
        if (front == -1)
        {
            cout << "empty" << endl;
            return -1;
        }
        int ans = arr[rear];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        cout << ans << " popped" << endl;
        return ans;
    }
    int popFront()
    {
        if (front == -1)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == size - 1)
        {
            front = 0;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        cout << ans << " deleted" << endl;
        return ans;
    }
};
int main()
{
    Deque q(5);
    q.pushFront(1);
    q.pushFront(2);
    q.pushFront(3);
    q.pushFront(4);
    q.popFront();
    q.popRear();
    return 0;
}