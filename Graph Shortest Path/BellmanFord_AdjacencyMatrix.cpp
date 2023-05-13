#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int n, vector<vector<int>> adj, int src)
{
    int u, v, w;
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j || !adj[i][j])
                    continue;
                u = i;
                v = j;
                w = adj[i][j];
                if (distance[u] != INT_MAX && (distance[u] + w) < distance[v])
                {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || !adj[i][j])
                continue;
            u = i;
            v = j;
            w = adj[i][j];
            if (distance[u] != INT_MAX && (distance[u] + w) < distance[v])
            {
                return {INT_MIN};
            }
        }
    }
    return distance;
}

int main()
{
    int n, src;
    cout << "Enter no. of Vertices : ";
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    cout << "Enter the Adjacency Matrix : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
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
    for (int i = 0; i < n; i++)
    {
        if (i == src)
            continue;
        cout << src << " -> " << i << " = " << distance[i] << endl;
    }
    return 0;
}