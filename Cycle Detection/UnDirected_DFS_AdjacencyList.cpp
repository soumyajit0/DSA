#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> adj, vector<int> &vis, int parent)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, node))
                return true;
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

bool cycle(int V, int E, vector<vector<int>> adj)
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, -1))
            {
                return true;
            }
        }
    }
    return false;
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
        adj[v].emplace_back(u);
    }
    if (cycle(V, E, adj))
    {
        cout << "Cycle is Present\n";
    }
    else
    {
        cout << "Cycle is Absent\n";
    }
    return 0;
}