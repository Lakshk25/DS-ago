#include <iostream>
#include <stack>
using namespace std;
int minCost(string str)
{
    if (str.size() % 2 != 0)
    {
        return -1;
    }
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
        {
            s.push(str[i]);
        }
        else
        {
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(str[i]);
            }
        }
    }
    int a = 0;
    int b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        s.pop();
    }
    return (a + 1) / 2 + (b + 1) / 2;
}
int main()
{
    string str = "}}}";
    cout << minCost(str);
    return 0;
}