#include <iostream>
#include <stdlib.h>

using namespace std;

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
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

void selection_sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        swap(&array[min_index], &array[i]);
    }
}

int main()
{
    int array_length;
    cout << "Enter the size of the array to be sorted: ";
    cin >> array_length;
    int array[array_length];

    for (int i = 0; i < array_length; i++)
    {
        array[i] = rand() % 1000;
    }

    print(array, array_length);
    selection_sort(array, array_length);
    print(array, array_length);

    return 0;
}