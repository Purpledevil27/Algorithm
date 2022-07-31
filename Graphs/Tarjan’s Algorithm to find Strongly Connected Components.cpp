// https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
// Time Complexity - O(V+E)

// A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
/*
Id: This is the time when a node is visited 1st time while DFS traversal.

Low: In the DFS tree, Tree edges take us forward, from the ancestor node to one of its descendants. Back edges take us backward, from a descendant node to one of its ancestors.

“Low” value of a node tells the topmost reachable ancestor (with minimum possible Id value) via the subtree of that node. So for any node, a Low value is equal to its Id value anyway (A node is the ancestor of itself).

Low value of u can change it in two cases:

-> Case1 (Tree Edge): If node v is not visited already, then after the DFS of v is complete, a minimum of low[u] and low[v] will be updated to low[u].
    low[u] = min(low[u], low[v]);
-> Case 2 (Back Edge): When child v is already visited, then a minimum of low[u] and id[v] will be updated to low[u].
    low[u] = min(low[u], id[v]);
*/

#include <bits/stdc++.h>
using namespace std;

void find(vector<int> adj[], int u, vector<int> &id, vector<int> &low, stack<int> &s, vector<bool> &onStack, int &time)
{
    // Initialize id and low value
    id[u] = low[u] = ++time;

    // Marking node on the stack
    onStack[u] = true;

    // Pushing node in the stack
    s.push(u);

    // Going through all the neighbours of the node
    for (auto v : adj[u])
    {
        if (id[v] == -1)
        {
            // if node is not visited then recur it
            find(adj, v, id, low, s, onStack, time);

            // Tree Edge, updating low value
            low[u] = min(low[u], low[v]);
        }
        else if (onStack[v])
        {
            // Back edge, updating low value
            low[u] = min(low[u], id[v]);
        }
    }

    // If we reach the end of the Strongly connected components then we pop the elements of SSC and output it.
    if (id[u] == low[u])
    {
        while (s.top() != u)
        {
            cout << s.top() << " ";
            onStack[s.top()] = false;
            s.pop();
        }
        cout << s.top() << " ";
        onStack[s.top()] = false;
        s.pop();
        cout << endl;
    }
}

// Finding strongly connected components
void ssc(vector<int> adj[], int v)
{
    vector<bool> onStack(v, false);
    vector<int> id(v, -1), low(v, INT_MAX);
    int time = 0;
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (id[i] == -1)
        {
            find(adj, i, id, low, s, onStack, time);
        }
    }
}

// Function to add edges
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    // Create graphs given in above diagrams
    cout << "Stronly connected components in first graph \n";
    int V = 5;
    vector<int> adj1[V];
    addEdge(adj1, 1, 0);
    addEdge(adj1, 0, 2);
    addEdge(adj1, 2, 1);
    addEdge(adj1, 0, 3);
    addEdge(adj1, 3, 4);
    ssc(adj1, V);

    cout << "\nStronly connected components in second graph \n";
    V = 4;
    vector<int> adj2[V];
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 2, 3);
    ssc(adj2, V);

    cout << "\nStronly connected components in third graph \n";
    V = 7;
    vector<int> adj3[V];
    addEdge(adj3, 0, 1);
    addEdge(adj3, 1, 2);
    addEdge(adj3, 2, 0);
    addEdge(adj3, 1, 3);
    addEdge(adj3, 1, 4);
    addEdge(adj3, 1, 6);
    addEdge(adj3, 3, 5);
    addEdge(adj3, 4, 5);
    ssc(adj3, V);

    return 0;
}