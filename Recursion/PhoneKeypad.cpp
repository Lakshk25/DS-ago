#include <iostream>
using namespace std;
class Solution
{
public:
    void solve(string digits, string output, vector<string> &ans, vector<string> alpha, int index)
    {
        if (index >= digits.size())
        {
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string str = alpha[number];
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            output.push_back(ch);
            solve(digits, output, ans, alpha, index + 1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        string output = "";
        vector<string> ans;
        int index = 0;
        if (digits.size() == 0)
        {
            return ans;
        }
        vector<string> alpha = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, ans, alpha, index);
        return ans;
    }
};
int main()
{

    return 0;
}