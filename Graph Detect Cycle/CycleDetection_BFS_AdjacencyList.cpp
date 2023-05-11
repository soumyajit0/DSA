#include <bits/stdc++.h>
using namespace std;

bool cycle(int n, int v, vector<int> adj[])
{
    return true;
}

int main()
{
    int n, v, a, b;
    cout << "Enter no. of Edges and Vertices : ";
    cin >> n >> v;
    vector<int> adj[v];
    cout << "Enter the Edges : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        adj[a].emplace_back(b);

        // Undirected Graph
        adj[a].emplace_back(b);
    }
    if (cycle(n, v, adj))
    {
        cout << "There is a Cycle in the Graph\n";
    }
    else
    {
        cout << "There is no Cycle in the Graph\n";
    }
}