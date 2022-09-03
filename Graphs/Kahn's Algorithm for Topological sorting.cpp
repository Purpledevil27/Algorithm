// Time Complexity: O(V+E)

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
// Topological Sorting for a graph is not possible if the graph is not a DAG.

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalsort(vector<vector<int>> &adj, int vertices)
{
    queue<int> q;
    // Creating a vector to store degree of all vertices
    vector<int> degree(vertices, 0);
    // Finding degree of the vertices
    for (int i = 0; i < vertices; i++)
    {
        for (auto &it : adj[i])
        {
            degree[it]++;
        }
    }

    // enqueue vertices with degree 0
    for (int i = 0; i < vertices; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // pushing back result
        topo.push_back(front);
        // Iterate through all its neighbouring nodesof dequeued node u and decrease their in-degree by 1
        for (auto &it : adj[front])
        {

            degree[it]--;
            // if degree becomes 0 then enqueue it
            if (degree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

int main()
{

    int vertices, edges;
    cout << "Number of vertices: ";
    cin >> vertices;
    cout << endl;

    cout << "Number of edges: ";
    cin >> edges;
    cout << endl;
    vector<vector<int>> adj(vertices);

    // Taking edges input
    for (int i = 0; i < edges; i++)
    {
        cout << "Edges " << i << ": ";
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        cout << endl;
    }
    // Topological sorting function
    vector<int> topo = topologicalsort(adj, vertices);

    // Printing result
    for (auto &it : topo)
    {
        cout << it << " ";
    }
    return 0;
}