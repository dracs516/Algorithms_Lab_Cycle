#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void delete_from_heap(int heap_array[], int *n)
{
    heap_array[1] = heap_array[*n];
    *n = *n - 1;
    int i = 1;
    while (i < *n)
    {
        int left = heap_array[2 * i];
        int right = heap_array[2 * i + 1];
        int larger_child = left > right ? 2 * i : 2 * i + 1;

        if (heap_array[i] < heap_array[larger_child])
        {
            swap(&heap_array[i], &heap_array[larger_child]);
            i = larger_child;
        }
        else
        {
            return;
        }
    }
}

void insert_in_heap(int heap_array[], int n, int value)
{
    // n = n + 1;
    heap_array[n] = value;
    int i = n;
    while (i > 1)
    {
        int parent = i / 2;
        if (heap_array[parent] < heap_array[i])
        {
            swap(&heap_array[parent], &heap_array[i]);
            i = parent;
        }
        else
        {
            return;
        }
    }
}

void print(int heap_array[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << heap_array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of heap: ";
    cin >> n;
    cout << "Enter the elements for MAX Heap: ";
    int heap_array[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;
        insert_in_heap(heap_array, i, value);
    }
    print(heap_array, n);
    cout << "Deleting root node" << endl;
    delete_from_heap(heap_array, &n);
    print(heap_array, n);
    return 0;
}