#include <iostream>
#include <stack>
using namespace std;
bool isRedundant(string str)
{
    stack<char> s;
    bool check = true;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            check = true;
            char top = s.top();
            while (s.top() != '(')
            {
                check = false;
                s.pop();
            }
            if (check)
            {
                return true;
            }
            s.pop();
        }
    }
    if (check)
    {
        return true;
    }
    return false;
}
int main()
{
    string str = "((a+b))";
    cout << isRedundant(str);
    return 0;
}