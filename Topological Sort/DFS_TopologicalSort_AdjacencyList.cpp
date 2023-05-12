#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, st);
    }
    st.push(node);
}

vector<int> topological_sort(int E, int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.emplace_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int E, V, u, v;
    cout << "Enter the no. of Edges and Vertices : ";
    cin >> E >> V;
    vector<int> adj[V];
    cout << "Enter the Adjacency List : \n";
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    vector<int> ans = topological_sort(E, V, adj);
    cout << "Topological Sort : \n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}