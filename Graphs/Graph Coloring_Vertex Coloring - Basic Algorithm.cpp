// https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/

#include <bits/stdc++.h>
using namespace std;

class Coloring
{
public:
    vector<int> assignColors(vector<vector<int>> &adj, int v)
    {
        // Initializing all the vertex as unassigned
        vector<int> vertex_color(v, -1);

        // Assign the first color to first vertex
        vertex_color[0] = 0;

        vector<bool> available_color(v, false);

        // Assign colors to remaining V-1 vertices
        for (int i = 1; i < v; i++)
        {
            // Process all adjacent vertices and flag their colors as unavailable
            for (auto u : adj[i])
            {
                if (vertex_color[u] != -1)
                {
                    available_color[vertex_color[u]] = true;
                }
            }

            // Find the first available color
            int color;
            for (int i = 0; i < v; i++)
            {
                if (!available_color[i])
                {
                    color = i;
                    break;
                }
            }

            // Assign the found color
            vertex_color[i] = color;

            // Reset the values back to false for the next iteration
            for (auto u : adj[i])
            {
                if (vertex_color[u] != -1)
                {
                    available_color[vertex_color[u]] = false;
                }
            }
        }
        return vertex_color;
    }
};

int main()
{

    int V, E;
    cin >> V >> E;

    // Adjacency list
    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Coloring obj;
    vector<int> vertex_color = obj.assignColors(adj, V);
    for (auto i : vertex_color)
    {
        cout << i << " ";
    }

    return 0;
}
