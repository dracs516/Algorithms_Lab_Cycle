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

vector<int> topo_sort(int n, vector<int> adj_list[])
{
    queue<int> q;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj_list[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj_list[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
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
        // adj_list[v].push_back(u);
    }

    print(adj_list, n);

    vector<int> topo = topo_sort(n, adj_list);

    cout << "Topological Sorting is: " << endl;
    for (int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " ";
    }
    cout << endl;

    return 0;
}