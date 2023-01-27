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
int partition(int arr[], int start, int end)
{
    int pivotElement = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start;
    int j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }

        while (arr[j] > pivotElement)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int part = partition(arr, start, end);
    quickSort(arr, start, part - 1);
    quickSort(arr, part + 1, end);
}
int main()
{
    int arr[] = {3, 5, 1, 2, 6, 0};
    int size = 6;
    print(arr, size);
    quickSort(arr, 0, size);
    print(arr, size);
    return 0;
}