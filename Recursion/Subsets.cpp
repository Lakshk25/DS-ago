#include <iostream>
#include <vector>
using namespace std;
void subsetMaker(vector<int> nums, vector<vector<int>> &ans, vector<int> output, int index)
{

    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    subsetMaker(nums, ans, output, index + 1);

    // include
    int element = nums[index];
    output.push_back(element);
    subsetMaker(nums, ans, output, index + 1);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    int index = 0;
    vector<vector<int>> ans;
    vector<int> output;
    subsetMaker(nums, ans, output, index);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    return 0;
}