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
void merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    int index = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[index++];
    }

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[index++];
    }

    int i = 0;
    int j = 0;
    int mainIndex = start;
    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
        {
            arr[mainIndex++] = first[i++];
        }
        else
        {
            arr[mainIndex++] = second[j++];
        }
    }
    while (i < len1)
    {
        arr[mainIndex++] = first[i++];
    }

    while (j < len2)
    {
        arr[mainIndex++] = second[j++];
    }
}

void mergeSort(int arr[], int start, int size)
{
    if (start >= size)
    {
        return;
    }
    int mid = start + (size - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, size);
    merge(arr, start, size);
}
int main()
{
    int arr[] = {3 , 5 , 1 , 2 , 6};
    int size = 5;
    print(arr, size);
    mergeSort(arr, 0, size);
    print(arr, 5);
    return 0;
}