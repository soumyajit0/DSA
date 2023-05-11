#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<int>> adj, int src)
{
    vector<int> final(n, 0);
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX, index = -1;
        for (int j = 0; j < n; j++)
        {
            if (distance[j] < min && final[j] == 0)
            {
                index = j;
                min = distance[j];
            }
        }
        final[index] = 1;
        for (int j = 0; j < n; j++)
        {
            if (adj[index][j] != 0 && (adj[index][j] + distance[index]) < distance[j] && final[j] == 0)
            {
                distance[j] = adj[index][j] + distance[index];
            }
        }
    }
    cout << "Parent Node\tNode\tDistance" << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == src)
            continue;
        cout << src << "\t" << i << "\t" << distance[i] << endl;
    }
}

int main()
{
    int n, src;
    cout << "Enter no. of nodes : ";
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    cout << "Enter the Adjacency List : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    cout << "Enter the Source Vertex : ";
    cin >> src;
    dijkstra(n, adj, src);
    return 0;
}