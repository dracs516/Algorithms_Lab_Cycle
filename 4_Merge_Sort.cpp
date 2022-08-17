#include <iostream>

using namespace std;

void print(int array[], int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void merge(int array[], int left, int mid, int right)
{
    int left_sub_array_length = mid - left + 1;
    int right_sub_array_length = right - mid;

    int left_sub_array[left_sub_array_length];
    int right_sub_array[right_sub_array_length];

    for (int i = 0; i < left_sub_array_length; i++)
    {
        left_sub_array[i] = array[left + i];
    }

    for (int i = 0; i < right_sub_array_length; i++)
    {
        right_sub_array[i] = array[mid + 1 + i];
    }

    int left_sub_array_pointer = 0, right_sub_array_pointer = 0, merged_array_pointer = left;

    while (left_sub_array_pointer < left_sub_array_length && right_sub_array_pointer < right_sub_array_length)
    {
        if (left_sub_array[left_sub_array_pointer] <= right_sub_array[right_sub_array_pointer])
        {
            array[merged_array_pointer] = left_sub_array[left_sub_array_pointer];
            left_sub_array_pointer++;
            merged_array_pointer++;
        }
        else
        {
            array[merged_array_pointer] = right_sub_array[right_sub_array_pointer];
            right_sub_array_pointer++;
            merged_array_pointer++;
        }
    }

    while (left_sub_array_pointer < left_sub_array_length)
    {
        array[merged_array_pointer] = left_sub_array[left_sub_array_pointer];
        left_sub_array_pointer++;
        merged_array_pointer++;
    }

    while (right_sub_array_pointer < right_sub_array_length)
    {
        array[merged_array_pointer] = right_sub_array[right_sub_array_pointer];
        right_sub_array_pointer++;
        merged_array_pointer++;
    }
}

void merge_sort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

int main()
{
    int array_length;
    cout << "Enter the length of the array: ";
    cin >> array_length;
    int array[array_length];

    for (int i = 0; i < array_length; i++)
    {
        array[i] = rand() % 1000;
    }

    print(array, array_length);
    merge_sort(array, 0, array_length - 1);
    print(array, array_length);

    return 0;
}