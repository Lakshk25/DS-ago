#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int arr[], int size)
{
    if (size == 0)
    {
        return;
    }
    if (size == 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, size - 1);
}
int main()
{
    int arr[] = {3, 9, 2, 1, 7, 3, 9};
    int size = 7;
    print(arr, size);
    bubbleSort(arr, size);
    print(arr, size);
    return 0;
}