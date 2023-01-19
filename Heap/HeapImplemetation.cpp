#include <iostream>
using namespace std;
class heap
{
public:
    int size;
    int arr[1000];
    heap()
    {
        size = 0;
        arr[0] = -1; // store 0th index as -1 (we start indexing from 1 in heap)
    }
    void insert(int data)
    {
        size = size + 1;

        // first insert node at end of array (leaf node)
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            // compare leaf node with its parent node (if leaf node is greater swap it with parent node)

            // time complexity O(logn);
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    // time complexity O(logn);
    // delete root
    void deleteFromHeap()
    {
        arr[1] = arr[size]; // store smallest data to root node
        size--;             //  reduce size

        int index = 1;
        while (index < size)
        {
            int leftNode = 2 * index;
            int rightNode = 2 * index + 1;
            // check if left child is greater than root and right child then swap it
            if (index < size && arr[leftNode] > arr[rightNode] && leftNode < size)
            {
                swap(arr[index], arr[leftNode]);
                index = leftNode;
            }
            // same to check right
            if (index < size && arr[rightNode] > arr[leftNode] && rightNode < size)
            {
                swap(arr[index], arr[rightNode]);
                index = rightNode;
            }
            // root is max
            else
                return;
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    heap h;
    h.insert(55);
    h.insert(50);
    h.insert(59);
    h.insert(45);
    h.insert(30);
    h.print();
    h.deleteFromHeap();
    h.print();
    return 0;
}