#include <iostream>
using namespace std;
bool checkPalindrome(string str, int s)
{
    int e = (str.size() - 1) - s;
    if (str[s] != str[e])
    {
        return 0;
    }
    if (s > e)
    {
        return 1;
    }
    s++;
    return checkPalindrome(str, s);
}
int main()
{
    string str = "abcba";
    cout << checkPalindrome(str, 0);
    return 0;
}