#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
    }
};
class stack
{
public:
    Node *top;
    stack()
    {
        top = NULL;
    }
    void push(int elem)
    {
        Node *newNode = new Node(elem);
        cout << newNode->data << " pushed in stack" << endl;
        newNode->prev = top;
        top = newNode;
    }
    void pop()
    {
        if (top != NULL)
        {
            Node *temp = top->prev;
            cout << top->data << " popped" << endl;
            delete top;
            top = temp;
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return;
        }
    }
    void peek()
    {
        cout << "stack top is " << top->data << endl;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    stack s;
    s.pop();
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.pop();
    s.pop();
    s.pop();
    s.peek();
    cout << s.isEmpty() << endl;
    return 0;
}