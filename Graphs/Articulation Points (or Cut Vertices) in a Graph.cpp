// https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
// Time Complexity - O(V+E)

/*
A vertex in an undirected connected graph is an articulation point (or cut vertex) if removing it (and edges through it) disconnects the graph.
Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network into 2 or more components.
They are useful for designing reliable networks.

For a disconnected undirected graph, an articulation point is a vertex removing which increases number of connected components.
*/

#include <bits/stdc++.h>
using namespace std;

void find(vector<int> adj[], int u, vector<bool> &visited, vector<bool> &isAP, vector<int> &low, vector<int> &disc, int &time, int parent)
{
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int children = 0;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            children++;
            // If v is not visited yet, then make it a child of u in DFS tree and recur for it
            find(adj, v, visited, isAP, low, disc, time, u);

            // Check if the subtree rooted with v has a connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If u is not root and low value of one of its child is more than discovery value of u.
            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = true;
        }
        // Update low value of u for parent function calls.
        else if (v != parent)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    // If u is root of DFS tree and has two or more children.
    if (parent == -1 && children > 1)
    {
        isAP[u] = true;
    }
}

void articulation_points(vector<int> adj[], int v)
{
    vector<bool> visited(v, false), isAP(v, false);
    vector<int> low(v, INT_MAX), disc(v, 0);
    int time = 0, parent = -1;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            find(adj, i, visited, isAP, low, disc, time, parent);
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (isAP[i])
            cout << i << " ";
    }
    cout << endl;
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    // Create graphs given in above diagrams
    cout << "Articulation points in first graph \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    articulation_points(adj1, V);

    cout << "\nArticulation points in second graph \n";
    V = 4;
    vector<int> adj2[V];
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 2, 3);
    articulation_points(adj2, V);

    cout << "\nArticulation points in third graph \n";
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
    articulation_points(adj3, V);

    return 0;
}