#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(int n, vector<vector<int>> &adj)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 0 && i != j)
            {
                adj[i][j] = INT_MAX;
            }
            else if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main()
{
    int n, u, v;
    cout << "Enter the no. of Vertices : ";
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    floyd_warshall(n, adj);
    cout << "Enter the Source Vertex and the Destination Vertex : \n";
    cin >> u >> v;
    for (int i = 0; i < n; i++)
    {
        if (adj[i][i] < 0)
        {
            cout << "Negative Cycle exists\n";
            return 0;
        }
    }
    if (adj[u][v] == INT_MAX)
    {
        cout << "No Path exists" << endl;
    }
    else
    {
        cout << "Shorted Distance from " << u << " to " << v << " is : " << adj[u][v] << endl;
    }
    return 0;
}