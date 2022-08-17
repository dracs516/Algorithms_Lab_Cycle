#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter the no. of vertices and edges: ";
    cin >> n >> m;

    cout << "Enter the edges: " << endl;

    int adj_matrix[n + 1][n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}