#include <bits/stdc++.h>
using namespace std;

int MSTCost(vector<int> cost)
{
    return accumulate(cost.begin(), cost.end(), 0);
}

void MST(int n, vector<int> parent, vector<int> cost)
{
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
            continue;
        cout << "Node " << parent[i] << " -> "
             << "Node " << i << endl;
    }
}

void prims(int n, vector<vector<int>> adj)
{
    vector<int> vis(n, 0);
    vector<int> parent(n, -1);
    vector<int> cost(n, INT_MAX);
    cost[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int index = -1, min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (cost[j] < min && vis[j] == 0)
            {
                index = j;
                min = cost[j];
            }
        }
        vis[index] = 1;
        for (int j = 0; j < n; j++)
        {
            if (adj[index][j] < cost[j] && vis[j] == 0 && adj[index][j] != 0)
            {
                cost[j] = adj[index][j];
                parent[j] = index;
            }
        }
    }
    cout << "MST Cost : " << MSTCost(cost) << endl;
    cout << "MST is : " << endl;
    MST(n, parent, cost);
}

int main()
{
    int n;
    cout << "Enter no. of nodes : ";
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    cout << "Enter the Adjacency List : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    prims(n, adj);
    return 0;
}