#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter the no. of vertices and edges: ";
    cin >> n >> m;
    vector<pair<int, int> > adj_list[n];

    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj_list[u].push_back(make_pair(v, weight));
        adj_list[v].push_back(make_pair(u, weight));
    }

    int parent_of_node[n];
    int key_weight[n];
    bool included_in_mst[n];

    for (int i = 0; i < n; i++)
    {
        key_weight[i] = INT_MAX;
        parent_of_node[i] = -1;
        included_in_mst[i] = false;
    }

    key_weight[0] = 0;
    parent_of_node[0] = -1;

    // Since we find the MST of a graph, we can say that there are no cycles and hence there is in total (n-1) edges if there are n vertices in the graph
    // Hence we iterate for count=0 to count < (n-1)

    for (int count = 0; count < n - 1; count++)
    {
        // minimum_check is initialized as INT_MAX so as to comapre it woth other key_weight and find the minimum one
        int minimum_check = INT_MAX;
        // The variable u is used to store the vertex index with the minimum key_weight in the upcoming loop
        int u;

        // Loop to get the minimum value of key weight of the graph
        for (int v = 0; v < n; v++)
        {
            // We check for included_in_mst false as we do not want nodes to be repeated. We just want the nodes not travelled and their weight to be the minimum one for the iteration
            if (included_in_mst[v] == false && key_weight[v] < minimum_check)
            {
                minimum_check = key_weight[v];
                u = v;
            }
        }

        included_in_mst[u] = true;

        for (auto it : adj_list[u])
        {
            // Since the vector is storing data of type Pair, so we can access those by using the keywords first and second
            // The keyword first will store the adjacent vertex whereas second will have the weight beetween the edges

            // The variable v will store the adjacent vertices for the vertex u in each iteration of the loop
            int v = it.first;
            // The variable weight will store the weight between vertex u and its adjacent vertices in each iteration of the loop
            int weight = it.second;

            // Now we check with the following condition if the adjacent vertex v has already been includedd or not
            // Also we check the minimum weight condition here
            if (included_in_mst[v] == false && weight < key_weight[v])
            {
                // The node v has been added to the MST adjacent to the node u
                // Hence u is the parent of node v
                parent_of_node[v] = u;

                // The miinimum weight from vertex u to v is stored in the key_weight matrix
                key_weight[v] = weight;
            }
        }
    }

    // Print the MST

    // We do not iterate over node 0 here as it will be covered using the parent_of _node matrix below
    int span_sum = 0;
    for (int i = 1; i < n; i++)
    {
        cout << parent_of_node[i] << " -> " << i << " -------> " << key_weight[i] << endl;
        span_sum += key_weight[i];
    }

    cout << "The weight of the MST is: " << span_sum << endl;
    return 0;
}