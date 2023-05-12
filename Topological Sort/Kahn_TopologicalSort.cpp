#include <bits/stdc++.h>
using namespace std;

void kahn(int V, int E, vector<vector<int>> adj)
{
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (!inDegree[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : adj[node])
        {
            if ((--inDegree[it]) == 0)
                q.push(it);
        }
    }
    cout << endl;
}

int main()
{
    int V, E, u, v;
    cout << "Enter the no. of Vertices and Edges : ";
    cin >> V >> E;
    vector<vector<int>> adj(V);
    cout << "Enter the Edges : \n";
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    cout << "Topological Sort : \n";
    kahn(V, E, adj);
    return 0;
}