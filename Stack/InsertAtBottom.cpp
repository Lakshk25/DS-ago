#include <iostream>
#include <stack>
using namespace std;
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
void traverse(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }cout<<endl;
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
    insertAtBottom(s, 0);
    traverse(s);
    return 0;
}