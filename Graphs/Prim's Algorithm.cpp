// Finding Minimum Spanning Tree || Time Complexity - O(VlogV)

#include <bits/stdc++.h>
using namespace std;

void prim(vector<vector<pair<int, int>>> &adj, int const &n)
{
    vector<int> weight(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    parent[0] = -1;
    visited[0] = true;
    weight[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    for (int i = 0; i < n - 1; i++)
    {
        int minVertex = pq.top().second;
        pq.pop();
        visited[minVertex] = true;

        for (auto &it : adj[minVertex])
        {
            int v = it.first, w = it.second;
            if (!visited[it.first] && weight[v] > w)
            {
                weight[v] = w;
                pq.push({w, v});
                parent[v] = minVertex;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Edge: " << parent[i] << " " << i << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> adj(v);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prim(adj, v);

    return 0;
}

// Finding Minimum Spanning Tree || Time Complexity - O(V^2)

#include <bits/stdc++.h>
using namespace std;

int findMinVertex(bool *visited, int *weight, int n)
{
    int min = INT_MAX;
    int minVertex = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && weight[i] < min)
        {
            min = weight[i];
            minVertex = i;
        }
    }
    return minVertex;
}

void prim(int **edges, int n)
{
    bool *visited = new bool[n];
    int *weight = new int[n];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    parent[0] = -1;
    int count = n;
    while (count--)
    {
        int minVertex = findMinVertex(visited, weight, n);
        visited[minVertex] = true;
        for (int i = 0; i < n; i++)
        {
            if (i == minVertex)
                continue;
            if (!visited[i] && edges[minVertex][i])
            {
                if (weight[i] > edges[minVertex][i])
                {
                    weight[i] = edges[minVertex][i];
                    parent[i] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << min(parent[i], i) << " " << max(parent[i], i) << " " << weight[i] << endl;
    }
    delete[] visited;
    delete[] parent;
    delete[] weight;
    return;
}

int main()
{
    int v, e;
    cin >> v >> e;

    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int first, second, weight;
        cin >> first >> second >> weight;
        edges[first][second] = weight;
        edges[second][first] = weight;
    }

    prim(edges, v);

    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}