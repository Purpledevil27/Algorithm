// Finding Shortest Distance from the source vertex (i.e. vertex 0) || Time Complexity = O(V^2)

#include <bits/stdc++.h>
using namespace std;

int findMinDistVertex(bool *visited, int *distance, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void dijkstra(int **edges, int n)
{
    bool *visited = new bool[n];
    int *distance = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minVertex = findMinDistVertex(visited, distance, n);
        visited[minVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && edges[minVertex][j])
            {
                if (distance[j] > edges[minVertex][j] + distance[minVertex])
                {
                    distance[j] = edges[minVertex][j] + distance[minVertex];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
    delete[] visited;
    delete[] distance;
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

    // Source Vertex = 0
    dijkstra(edges, v);

    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}