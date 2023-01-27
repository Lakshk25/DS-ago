#include <iostream>
#include <vector>
using namespace std;
void setMaker(string str, string output, vector<string> &ans, int index)
{
    if (index >= str.size())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    // for include
    setMaker(str, output, ans, index + 1);
    // for exclude
    char element = str[index];
    output.push_back(element);
    setMaker(str, output, ans, index + 1);
}
vector<string> subsequences(string str)
{
    vector<string> ans;
    string output;
    int index = 0;
    setMaker(str, output, ans, index);
    return ans;
}

int main()
{

    return 0;
}