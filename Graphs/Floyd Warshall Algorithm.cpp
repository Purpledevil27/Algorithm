// Finding all pairs Shortest Path  || Time complexity = O(N^3)

#include <bits/stdc++.h>
using namespace std;

class floydWarshallAglorithm
{
public:
    void fwa(vector<vector<int>> &graph)
    {
        vector<vector<int>> dist = graph;
        int n = graph.size();
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        printSolution(dist);
    }

    /* A utility function to print solution */
    void printSolution(vector<vector<int>> &dist)
    {
        int V = dist.size();
        cout << "The following matrix shows the shortest "
                "distances"
                " between every pair of vertices \n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] == INT_MAX)
                    cout << "INF"
                         << "     ";
                else
                    cout << dist[i][j] << "     ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int V = 4;
    int graph[V][V] = {{0, 5, INT_MAX, 10},
                       {INT_MAX, 0, 3, INT_MAX},
                       {INT_MAX, INT_MAX, 0, 1},
                       {INT_MAX, INT_MAX, INT_MAX, 0}};
    vector<vector<int>> g(V, vector<int>(V));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            g[i][j] = graph[i][j];
        }
    }
    floydWarshallAglorithm obj;
    obj.fwa(g);
    return 0;
}