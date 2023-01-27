#include <iostream>
#include <stack>
using namespace std;
class NStack
{
private:
    int *arr;
    int *top;
    int *next;
    int freeSpace;
public:
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        for (int i = 0; i < S; i++)
        {
            next[i] = i + 1;
        }
        next[S - 1] = -1;
        for (int i = 0; i < N; i++)
        {
            top[i] = -1;
        }
        freeSpace = 0;
    }
    bool push(int x, int m)
    {
        if (freeSpace == -1)
        {
            cout << "Stack is full" << endl;
            return false;
        }
        int index = freeSpace;
        freeSpace = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
        cout << x << " pushed in stack " << m << endl;
        return true;
    }
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            cout << "underflow" << endl;
            return -1;
        }
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freeSpace;
        freeSpace = index;
        return arr[index];
    }
};
int main()
{
    NStack s(3, 6);
    s.push(5, 1);
    s.push(6, 2);
    s.push(3, 3);
    s.push(6, 1);
    s.push(8, 1);
    s.push(6, 3);
    // s.push(6 , 3);
    s.pop(1);
    s.pop(3);
    return 0;
}