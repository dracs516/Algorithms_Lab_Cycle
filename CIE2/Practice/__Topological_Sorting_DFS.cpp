#include <iostream>
#include <vector>
#include <stack>

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

void find_topo(int node, vector<int> &visited_node, vector<int> adj_list[], stack<int> &st)
{
    visited_node[node] = 1;

    for (auto it : adj_list[node])
    {
        if (!visited_node[it])
        {
            find_topo(it, visited_node, adj_list, st);
        }
    }
    st.push(node);
}

vector<int> topo_sort(int n, vector<int> adj_list[])
{
    stack<int> st;
    vector<int> visited_node(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited_node[i] == 0)
        {
            find_topo(i, visited_node, adj_list, st);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
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

    return 0;
}