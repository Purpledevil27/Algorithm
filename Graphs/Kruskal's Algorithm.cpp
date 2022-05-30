// Finding Minimum Spanning Tree using Union-Find || Time Complexity - O(ElogE + V^2)
#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;

    Edge()
    {
    }

    Edge(int s, int d, int w)
    {
        source = s;
        destination = d;
        weight = w;
    }
};

bool sortbyweight(Edge const &a, Edge const &b)
{
    return a.weight < b.weight;
}

void print(Edge *input, int v)
{
    for (int i = 0; i < v; i++)
        cout << input[i].source << " " << input[i].destination << " " << input[i].weight << endl;
}

int findParent(int parent[], int v1)
{
    if (parent[v1] == v1)
    {
        return v1;
    }
    return findParent(parent, parent[v1]);
}

void Kruskal(Edge *input, Edge *output, int v)
{
    int *parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count < v - 1)
    {
        int v1 = input[i].source;
        int v2 = input[i].destination;

        int source_parent = findParent(parent, v1);
        int destination_parent = findParent(parent, v2);

        if (destination_parent != source_parent)
        {
            output[count++] = Edge(min(v1, v2), max(v1, v2), input[i].weight);
            parent[source_parent] = destination_parent;
            i++;
        }
        else
        {
            i++;
        }
    }
    delete[] parent;
}

int main()
{
    int v, e;
    cin >> v >> e;
    Edge *input = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i] = Edge(s, d, w);
    }

    Edge *output = new Edge[v - 1];
    sort(input, input + e, sortbyweight);

    Kruskal(input, output, v);
    print(output, v - 1);

    delete[] input;
    delete[] output;

    return 0;
}
