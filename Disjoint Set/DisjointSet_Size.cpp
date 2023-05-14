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

int main()
{
    int n, E, u, v;
    cout << "Enter the no. of Nodes : ";
    cin >> n;
    vector<int> size(n + 1, 1), parent(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    cout << "Enter no. of Edges : ";
    cin >> E;
    cout << "Enter the Edges : \n";
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        unionBySize(u, v, size, parent);
    }
    cout << "Enter the Edges to check if they are connected : ";
    cin >> u >> v;
    if (findPar(u, parent) == findPar(v, parent))
    {
        cout << "They are connected\n";
    }
    else
    {
        cout << "They are not connected\n";
    }
    return 0;
}