// https://www.geeksforgeeks.org/strongly-connected-components/

/* A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC)
of a directed graph is a maximal strongly connected subgraph.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void countSSC(vector<int> adj[], vector<bool> &visited, int i)
    {
        if (visited[i])
        {
            return;
        }
        // To output all the group of SSC
        // cout << i << " ";
        visited[i] = true;
        for (auto p : adj[i])
        {
            countSSC(adj, visited, p);
        }
    }

    void dfs(vector<int> adj[], vector<bool> &visited, int n, int i, stack<int> &stack)
    {
        if (visited[i])
        {
            return;
        }

        visited[i] = true;
        for (auto node : adj[i])
        {
            dfs(adj, visited, n, node, stack);
        }
        stack.push(i);
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        stack<int> stack;

        // Calling dfs to fill the stack
        for (int i = 0; i < V; i++)
        {
            dfs(adj, visited, V, i, stack);
        }

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        vector<int> adj2[V];

        // Reversing the directions of the elements
        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                adj2[j].push_back(i);
            }
        }

        int count = 0;

        while (!stack.empty())
        {
            int node = stack.top();
            stack.pop();

            // Calling dfs again on the new adjacency list until the stack is not empty
            if (!visited[node])
            {
                count++;
                countSSC(adj2, visited, node);
                // cout << endl;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        // Adjacency list
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends