// https://www.geeksforgeeks.org/bridge-in-a-graph/
// Time Complexity - O(V+E)

/*
An edge in an undirected connected graph is a bridge if removing it disconnects the graph.
For a disconnected undirected graph, definition is similar, a bridge is an edge removing which increases number of disconnected components.

Like Bridges, bridges represent vulnerabilities in a connected network and are useful for designing reliable networks.
For example, in a wired computer network, an articulation point indicates the critical computers and a bridge indicates the critical wires or connections.

The condition for an edge (u, v) to be a bridge is, “low[v] > disc[u]”.
*/

#include <bits/stdc++.h>
using namespace std;

void find(vector<int> adj[], int u, vector<int> &low, vector<int> &disc, int &time, int parent)
{
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all the adjacent vertices of u
    for (auto v : adj[u])
    {
        if (disc[v] == -1)
        {
            // If v is not visited yet, recur for it
            find(adj, v, low, disc, time, u);

            // Check if the subtree rooted with v has a connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If u is not root and low value of one of its child is more than discovery value of u.
            if (low[v] > disc[u])
                cout << u << " " << v << endl;
        }
        // Update low value of u for parent function calls.
        else if (v != parent)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void bridges(vector<int> adj[], int v)
{
    vector<int> low(v, INT_MAX), disc(v, -1);
    int time = 0, parent = -1;

    for (int i = 0; i < v; i++)
    {
        if (disc[i] == -1)
        {
            find(adj, i, low, disc, time, parent);
        }
    }
}

// Function to add edges
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    // Create graphs given in above diagrams
    cout << "Bridges in first graph \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    bridges(adj1, V);

    cout << "\nBridges in second graph \n";
    V = 4;
    vector<int> adj2[V];
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 2, 3);
    bridges(adj2, V);

    cout << "\nBridges in third graph \n";
    V = 7;
    vector<int> adj3[V];
    addEdge(adj3, 0, 1);
    addEdge(adj3, 1, 2);
    addEdge(adj3, 2, 0);
    addEdge(adj3, 1, 3);
    addEdge(adj3, 1, 4);
    addEdge(adj3, 1, 6);
    addEdge(adj3, 3, 5);
    addEdge(adj3, 4, 5);
    bridges(adj3, V);

    return 0;
}