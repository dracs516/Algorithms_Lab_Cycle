#include <iostream>
#include <iomanip>

using namespace std;

void print(int array[][4])
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << std::setw(10);
            std::cout << array[i][j] << " ";
        }
        std::cout << endl;
    }
}

void floyd_algorithm(int array[][4])
{
    int n = 4;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i][j] = min(array[i][j], array[i][k] + array[k][j]);
            }
        }
    }
    cout << "All pair shortest path is: " << endl;
    print(array);
}

int main()
{
    int array[4][4];
    int n = 4;
    cout << "Insert element in array: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> array[i][j];
        }
    }
    print(array);
    floyd_algorithm(array);
    return 0;
}