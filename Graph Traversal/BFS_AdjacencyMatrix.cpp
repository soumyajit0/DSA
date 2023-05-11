#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<vector<int>> adj)
{
    vector<int> vis(n, 0);
    vector<int> traversal;
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        traversal.emplace_back(node);
        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] != 0 && vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
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
    vector<int> traversal = bfs(n, adj);
    cout << "BFS Traversal : " << endl;
    for (auto it : traversal)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}