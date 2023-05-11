#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<int> adj[])
{
    queue<int> q;
    vector<int> vis(n, 0);
    vis[0] = 1;
    q.push(0);
    vector<int> traversal;
    while (!q.empty())
    {
        int node = q.front();
        traversal.emplace_back(node);
        q.pop();
        for (int it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return traversal;
}

int main()
{
    int n;
    cout << "Enter no. of edges : ";
    cin >> n;
    vector<int> adj[n];
    cout << "Enter the edges : \n";
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    cout << "BFS Traversal : \n";
    vector<int> traversal = bfs(n, adj);
    for (int it : traversal)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}