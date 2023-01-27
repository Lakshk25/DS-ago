#include <iostream>
#include <stack>
using namespace std;
void traverse(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void insertAtBottom(stack<int> &s, int elem)
{
    if (s.empty())
    {
        s.push(elem);
        return;
    }
    int top = s.top();
    s.pop();
    insertAtBottom(s, elem);
    s.push(top);
}
void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, top);
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    traverse(s);
    reverse(s);
    traverse(s);
    return 0;
}