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

void dfs(int node, vector<int> adj_list[], int visited_node[], vector<int> &dfs_list)
{
    visited_node[node] = 1;
    dfs_list.push_back(node);

    for (auto it : adj_list[node])
    {
        if (!visited_node[it])
        {
            dfs(it, adj_list, visited_node, dfs_list);
        }
    }
}

vector<int> dfs_of_graph(int n, vector<int> adj_list[])
{
    int visited_node[n];
    for (int i = 0; i < n; i++)
    {
        visited_node[i] = 0;
    }
    int start_node = 0;
    vector<int> dfs_list;
    dfs(start_node, adj_list, visited_node, dfs_list);
    return dfs_list;
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

    vector<int> dfs_list = dfs_of_graph(n, adj_list);

    cout << "DFS Traversal is: " << endl;
    for (int i = 0; i < dfs_list.size(); i++)
    {
        cout << dfs_list[i] << " ";
    }

    return 0;
}