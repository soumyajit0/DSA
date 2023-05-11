#include <bits/stdc++.h>
using namespace std;

void dfs_recursion(int node, vector<int> adj[], vector<int> &vis, vector<int> &traversal)
{
    vis[node] = 1;
    traversal.emplace_back(node);
    for (int it : adj[node])
    {
        if (!vis[it])
        {
            dfs_recursion(it, adj, vis, traversal);
        }
    }
}

vector<int> dfs(int n, vector<int> adj[])
{
    int start = 0;
    vector<int> vis(n, 0);
    vector<int> traversal;
    dfs_recursion(start, adj, vis, traversal);
    return traversal;
}

int main()
{
    int n, m;
    cout << "Enter no. of node and edges : ";
    cin >> n >> m;
    vector<int> adj[n];
    cout << "Enter the edges : \n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    cout << "DFS Traversal : \n";
    vector<int> traversal = dfs(n, adj);
    for (int it : traversal)
        cout << it << " ";
    cout << endl;
    return 0;
}