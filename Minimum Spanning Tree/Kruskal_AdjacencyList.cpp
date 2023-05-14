#include <bits/stdc++.h>
using namespace std;

int findPar(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findPar(parent[node], parent);
}

void unionBySize(int u, int v, vector<int> &size, vector<int> &parent)
{
    int ulp_u = findPar(u, parent);
    int ulp_v = findPar(v, parent);
    if (ulp_u == ulp_v)
        return;
    if (size[ulp_u] > size[ulp_v])
    {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
    else
    {
        parent[ulp_v] = ulp_u;
        size[ulp_v] += size[ulp_u];
    }
}

vector<vector<int>> kruskal(int V, int E, vector<vector<int>> adj[], vector<int> &size, vector<int> &parent)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjNode = it[0];
            int wt = it[1];
            pq.push({wt, {i, adjNode}});
        }
    }
    vector<vector<int>> MST;
    int MSTwt = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        if (findPar((it.second).first, parent) != findPar((it.second).second, parent))
        {
            unionBySize((it.second).first, (it.second).second, size, parent);
            MSTwt += it.first;
            vector<int> t;
            t.emplace_back((it.second).first);
            t.emplace_back((it.second).second);
            MST.emplace_back(t);
        }
    }
    cout << "Minimum Weight : " << MSTwt << endl;
    return MST;
}

int main()
{
    int V, E, wt, u, v;
    cout << "Enter the no. of Vertices and Edges : ";
    cin >> V >> E;
    vector<int> size(V + 1, 0), parent(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
    vector<vector<int>> adj[V];
    cout << "Enter the Edges with their Weights : \n";
    for (int i = 0; i < E; i++)
    {
        vector<int> t1, t2;
        cin >> wt >> u >> v;
        t1.emplace_back(u);
        t1.emplace_back(wt);
        adj[v].emplace_back(t1);
        t2.emplace_back(v);
        t2.emplace_back(wt);
        adj[u].emplace_back(t2);
    }
    vector<vector<int>> MST = kruskal(V, E, adj, size, parent);
    cout << "MST : \n";
    for (auto it : MST)
    {
        cout << it[0] << " -> " << it[1] << endl;
    }
    return 0;
}