#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>> adj, int src)
{
    vector<int> final(n, 0);
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int index = -1, min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (distance[j] < min && !final[j])
            {
                min = distance[j];
                index = j;
            }
        }
        final[index] = 1;
        for (int j = 0; j < n; j++)
        {
            if (adj[index][j] != 0 && !final[j] && (adj[index][j] + distance[index]) < distance[j])
            {
                distance[j] = adj[index][j] + distance[index];
            }
        }
    }
    return distance;
}

int main()
{
    int n, src;
    cout << "Enter no. of Nodes : ";
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
    vector<int> distance = dijkstra(n, adj, src);
    cout << "Minimum Distance : \n";
    for (int i = 0; i < n; i++)
    {
        if (i == src)
            continue;
        cout << src << " -> " << i << " = " << distance[i] << endl;
    }
    return 0;
}