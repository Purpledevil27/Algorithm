// Finding Shortest Distance from the source vertex (i.e. vertex 0) || Time Complexity = O(VlogV)

#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &adj, int const &n, int const &source)
{
    // create a vector to store the distance of all the vertices from the source
    vector<int> distance(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap
    // keep the distance 0 to the source
    distance[source] = 0;
    // push {distance, vertices} to the min heap.
    pq.push({0, source});
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for (auto &it : adj[prev])
        {
            // check if the distance travel to the next vertex is less using the current path/vertex.
            if (distance[it.first] > dist + it.second)
            {
                distance[it.first] = dist + it.second;
                pq.push({distance[it.first], it.first});
            }
        }
    }
    // Printing the result
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
    return;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> adj(v);

    for (int i = 0; i < e; i++)
    {
        // taking inputs
        int first, second, weight;
        cin >> first >> second >> weight;
        adj[first].push_back({second, weight});
    }

    // Source Vertex = 5
    int source = 5;
    dijkstra(adj, v, source);

    return 0;
}

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