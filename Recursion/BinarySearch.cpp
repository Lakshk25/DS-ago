#include <iostream>
using namespace std;
int search(int arr[], int start, int end, int element)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == element)
    {
        return mid;
    }
    else if (arr[mid] > element)
    {
        return search(arr, start, mid - 1, element);
    }
    else
    {
        return search(arr, mid + 1, end, element);
    }
}
int binary(int arr[], int size, int element)
{
    return search(arr, 0, size, element);
}
int main()
{
    int arr[] = {2, 3, 7, 9, 10};
    int size = 5;
    int element = 9;
    cout << binary(arr , size , element);
    return 0;
}