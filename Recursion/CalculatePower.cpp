#include <iostream>
using namespace std;
int calculatePower(int num, int power)
{
    if (power == 0)
    {
        return 1;
    }
    if (power == 1)
    {
        return num;
    }
    // if (power % 2 == 0)          // Works
    // {
    //     return calculatePower(num * num, power / 2);
    // }
    // else
    // {
    //     return calculatePower(num * (num * num), power / 2);
    // }

    int ans = calculatePower(num, power / 2);
    if (power % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return num * (ans * ans);
    }
}
int main()
{
    int num = 3;
    int power = 3;
    cout << calculatePower(num, power);
    return 0;
}