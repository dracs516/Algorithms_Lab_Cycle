#include <iostream>
#include <stdlib.h>

using namespace std;

void print(int array[], int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right)
{
    // pivot element as last element
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return (i + 1);
}

void quick_sort(int array[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(array, left, right);
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

int main()
{
    int array_length;
    cout << "Enter the size of array: ";
    cin >> array_length;
    int array[array_length];

    for (int i = 0; i < array_length; i++)
    {
        array[i] = rand() % 1000;
    }

    print(array, array_length);
    quick_sort(array, 0, array_length - 1);
    print(array, array_length);

    return 0;
}