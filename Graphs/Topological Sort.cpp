// Time Complexity - O(V+E)
// https://www.geeksforgeeks.org/topological-sorting/
// Strictly used in directed acylic graph
// Can be used to detect cycle in a graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void sort(vector<vector<int>> &adj, vector<bool> &visited, int node, vector<int> &ans)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                sort(adj, visited, i, ans);
            }
        }
        ans.push_back(node);
    }

public:
    vector<int> topologicalSort(vector<vector<int>> &adj, int n)
    {
        vector<int> ans;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                sort(adj, visited, i, ans);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int v, e;
    cin >> v >> e;

    // DIRECTED ACYCLIC GRAPH
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        adj[f].push_back(s);
    }

    Solution obj;
    vector<int> sort = obj.topologicalSort(adj, v);
    for (auto i : sort)
    {
        cout << i << " ";
    }
    return 0;
}