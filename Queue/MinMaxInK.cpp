#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void minMax(vector<int> v, int k)
{
    deque<int> maxi;
    deque<int> mini;

    // for 1st window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && v[maxi.back()] <= v[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && v[mini.back()] >= v[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    cout << " sum is " << v[maxi.front()] + v[mini.front()]<<endl;

    // for remaining window
    for (int i = k; i < v.size(); i++)
    {
        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition
        while (!maxi.empty() && v[maxi.back()] <= v[i])
        {
            maxi.pop_back();
        }

        while (!mini.empty() && v[mini.back()] >= v[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
         cout << " sum is " << v[maxi.front()] + v[mini.front()]<<endl;
    }
}
int main()
{
    vector<int> v = {-1, 2, -5, 6, 7, -2, 8};
    int window = 3;
    minMax(v, window);
    return 0;
}