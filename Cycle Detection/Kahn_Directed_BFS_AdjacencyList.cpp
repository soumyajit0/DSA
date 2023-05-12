#include <bits/stdc++.h>
using namespace std;

bool kahn(int V, int E, vector<vector<int>> adj)
{
    int count = 0;
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
        count++;
        for (auto it : adj[node])
        {
            if ((--inDegree[it]) == 0)
                q.push(it);
        }
    }
    if (count != V)
    {
        return true;
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
    }
    if (kahn(V, E, adj))
    {
        cout << "Cycle is Present\n";
    }
    else
    {
        cout << "Cycle is Absent\n";
    }
    return 0;
}