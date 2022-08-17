#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap_array[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && heap_array[left] > heap_array[largest])
    {
        largest = left;
    }
    if (right <= n && heap_array[right] > heap_array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&heap_array[largest], &heap_array[i]);
        heapify(heap_array, n, largest);
    }
}

void build_heap(int heap_array[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(heap_array, n, i);
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

void heap_sort(int heap_array[], int n)
{
    build_heap(heap_array, n);
    print(heap_array, n);
    for (int i = n; i > 1; i--)
    {
        swap(&heap_array[1], &heap_array[i]);
        heapify(heap_array, i - 1, 1);
    }
    cout << "Sorted Array: " << endl;
    print(heap_array, n);
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
        heap_array[i] = value;
    }
    print(heap_array, n);
    heap_sort(heap_array, n);
    return 0;
}