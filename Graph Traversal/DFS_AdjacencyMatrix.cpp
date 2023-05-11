#include <bits/stdc++.h>
using namespace std;

void dfs_recursion(int node, int n, vector<vector<int>> adj, vector<int> &vis, vector<int> &traversal)
{
    vis[node] = 1;
    traversal.emplace_back(node);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && adj[node][i] != 0)
        {
            dfs_recursion(i, n, adj, vis, traversal);
        }
    }
}

vector<int> dfs(int n, vector<vector<int>> adj)
{
    vector<int> vis(n, 0);
    vector<int> traversal;
    int start = 0;
    dfs_recursion(start, n, adj, vis, traversal);
    return traversal;
}

int main()
{
    int n;
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
    vector<int> traversal = dfs(n, adj);
    cout << "DFS Traversal : " << endl;
    for (auto it : traversal)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}