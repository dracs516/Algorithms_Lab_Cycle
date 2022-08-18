#include <iostream>
#include <iomanip>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knap_sack(int W, int wt[], int val[], int n)
{
    int v[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                v[i][w] = 0;
            }
            else if (w < wt[i - 1])
            {
                v[i][w] = v[i - 1][w];
            }
            else
            {
                v[i][w] = max(val[i - 1] + v[i - 1][w - wt[i - 1]], v[i - 1][w]);
            }
        }
    }

    // cout << "------------------------" << endl;
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         std::cout << std::setw(3);
    //         std::cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int w = W;
    int res = v[n][W];
    for (int i = n; i > 0; i--)
    {
        if (res == v[i - 1][w])
        {
            continue;
        }
        else
        {
            cout << wt[i - 1] << " ";
            res -= val[i - 1];
            w = w - wt[i - 1];
        }
    }
    cout << endl;

    return v[n][W];
}

int main()
{
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int W = 50;
    // int wt[] = {1, 3, 4, 6};
    // int val[] = {20, 30, 10, 50};
    // int W = 10;
    int n = sizeof(val) / sizeof(val[0]);
    cout << endl;
    cout << "The selection of item is as follows: " << endl;
    int max_profit = knap_sack(W, wt, val, n);
    cout << "Maximum Profit is: " << max_profit << endl;
}