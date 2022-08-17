#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int> adj_list[], int n)
{
    cout << "Adjacency List is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "vertex " << i;
        for (auto it : adj_list[i])
        {
            cout << " -> " << it;
        }
        cout << endl;
    }
}

vector<int> bfs_of_graph(int n, vector<int> adj_list[])
{
    int visited_node[n];
    for (int i = 0; i < n; i++)
    {
        visited_node[i] = 0;
    }
    visited_node[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj_list[node])
        {
            if (!visited_node[it])
            {
                visited_node[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
    int n, m;
    cout << "Enter thee no. of vertices and edges: ";
    cin >> n >> m;

    vector<int> adj_list[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    print(adj_list, n);

    vector<int> bfs = bfs_of_graph(n, adj_list);

    cout << "BFS Traversal is: " << endl;
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
    cout << endl;

    return 0;
}