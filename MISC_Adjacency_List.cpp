#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> adj_list[], int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        cout << "vertex " << i;
        for (auto it : adj_list[i])
        {
            cout << " -> " << it;
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the no. of vertices and edges: ";
    cin >> n >> m;
    vector<int> adj_list[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    print(adj_list, n);
}