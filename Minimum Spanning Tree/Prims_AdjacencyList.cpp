#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> prims(int V, vector<vector<int>> adj)
{
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>, greater<pair<pair<int, int>, int>>>> pq;
    vector<pair<int, int>> mst(V);
    vector<int> vis(V, 0);
    vector<int> parent(V, -1);
    vector<int> cost(V, INT_MAX);
    pq.push({{0, 0}, -1});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = (it.first).first;
        int node = (it.first).second;
        int par = it.second;
        if (vis[node])
        {
            continue;
        }
        vis[node] = 1;
        cost[node] = wt;
        parent[node] = par;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int wt = it[1];
            if (!vis[adjNode])
            {
                pq.push({{wt, adjNode}, node});
            }
        }
    }
    cout << "MST Cost : " << accumulate(cost.begin(), cost.end(), 0) << endl;
    for (int i = 0; i < V; i++)
    {
        mst[i] = {i, parent[i]};
    }
    return mst;
}

int main()
{
    int V, E, u, v, wt;
    cout << "Enter the no. of Edges and Vertices : ";
    cin >> E >> V;
    vector<vector<int>> adj(V);
    cout << "Enter the Parent Vertex, Destination Vertex and Weight : \n";
    for (int i = 0; i < E; i++)
    {
        vector<int> t1, t2;
        cin >> u >> v >> wt;
        t1.emplace_back(v);
        t1.emplace_back(wt);
        adj[u].emplace_back(t1);
        t2.emplace_back(u);
        t2.emplace_back(wt);
        adj[v].emplace_back(t2);
    }
    vector<pair<int, int>> mst = prims(V, adj);
    cout << "MST : \n";
    for (auto it : mst)
    {
        cout << it.first << " -> " << it.second << endl;
    }
    return 0;
}