#include <iostream>

using namespace std;

int parent_of[10];
int rank_of[10];
int n;

void makeSet()
{
    for (int i = 1; i <= n; i++)
    {
        parent_of[i] = i;
        rank_of[i] = 0;
    }
}

int find_parent(int node)
{
    if (node == parent_of[node])
    {
        return node;
    }
    else
    {
        return parent_of[node] = find_parent(parent_of[node]);
    }
}

void union_of(int u, int v)
{
    u = find_parent(u);
    v = find_parent(v);

    if (rank_of[u] < rank_of[v])
    {
        parent_of[u] = v;
    }
    else if (rank_of[v] > rank_of[u])
    {
        parent_of[v] = u;
    }
    else
    {
        parent_of[v] = u;
    }
}

int main()
{
    cout << "Enter the no. of vertices: ";
    cin >> n;
    makeSet();
    return 0;
}