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