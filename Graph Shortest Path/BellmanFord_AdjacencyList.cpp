#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int vertices, vector<vector<int>> adj, int src)
{
    int u, v, w;
    vector<int> distance(vertices, INT_MAX);
    distance[src] = 0;
    for (int i = 0; i < vertices - 1; i++)
    {
        for (auto it : adj)
        {
            u = it[0];
            v = it[1];
            w = it[2];
            if (distance[u] != INT_MAX && (distance[u] + w) < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }
    for (auto it : adj)
    {
        u = it[0];
        v = it[1];
        w = it[2];
        if (distance[u] != INT_MAX && (distance[u] + w) < distance[v])
        {
            return {INT_MIN};
        }
    }
    return distance;
}

int main()
{
    int n, vertices, src;
    cout << "Enter no. of Edges and Vertices : ";
    cin >> n >> vertices;
    vector<vector<int>> adj(n, vector<int>(3, 0));
    cout << "Enter the Parent Vertex, Desitination Vertex and Edge Weight : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> adj[i][0] >> adj[i][1] >> adj[i][2];
    }
    cout << "Enter the Source Vertex : ";
    cin >> src;
    vector<int> distance = bellman_ford(n, adj, src);
    if (distance.size() == 1 && distance[0] == INT_MIN)
    {
        cout << "Negative Cycle exists\n";
        return 0;
    }
    cout << "Minimum Distance : \n";
    for (int i = 0; i < vertices; i++)
    {
        if (i == src)
            continue;
        cout << src << " -> " << i << " = " << distance[i] << endl;
    }
    return 0;
}