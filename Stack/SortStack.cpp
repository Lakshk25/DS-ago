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
void sort(stack<int> &s, int elem)
{
    if (s.empty() || s.top() < elem)
    {
        s.push(elem);
        return;
    }
    int top = s.top();
    s.pop();
    sort(s, elem);
    s.push(top);
}
void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    sortStack(s);
    sort(s, top);
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(5);
    s.push(8);
    s.push(3);
    s.push(9);
    traverse(s);
    sortStack(s);
    traverse(s);
    return 0;
}