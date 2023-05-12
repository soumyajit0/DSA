#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int n, vector<vector<int>> adj, vector<int> &vis, vector<int> &recSt)
{
    vis[node] = 1;
    recSt[node] = 1;
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 0)
            continue;
        if (!vis[i] && dfs(i, n, adj, vis, recSt))
        {
            return true;
        }
        else if (recSt[i])
        {
            return true;
        }
    }
    recSt[node]=0;
    return false;
}

bool cycle(int n, vector<vector<int>> adj)
{
    vector<int> vis(n, 0);
    vector<int> recSt(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, n, adj, vis, recSt))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
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
    if (cycle(n, adj))
    {
        cout << "Cycle is Present\n";
    }
    else
    {
        cout << "Cycle is Absent\n";
    }
    return 0;
}