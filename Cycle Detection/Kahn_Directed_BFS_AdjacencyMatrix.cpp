#include <bits/stdc++.h>
using namespace std;

bool kahn(int n, vector<vector<int>> adj)
{
    int count = 0;
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != 0)
            {
                inDegree[j]++;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 0)
                continue;
            if ((--inDegree[i]) == 0)
            {
                q.push(i);
            }
        }
    }
    if (count != n)
    {
        return true;
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
    if (kahn(n, adj))
    {
        cout << "Cycle is Present\n";
    }
    else
    {
        cout << "Cycle is Absent\n";
    }
}