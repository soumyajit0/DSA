#include <bits/stdc++.h>
using namespace std;

void maze(string s, int n, int m, int i, int j, vector<vector<int>> obstacles)
{
    if (i == n && j == m)
    {
        cout << s << endl;
        return;
    }
    if (obstacles[i][j] == 1)
    {
        return;
    }
    if (i < n)
    {
        maze(s + "V", n, m, i + 1, j, obstacles);
    }
    if (j < m)
    {
        maze(s + "H", n, m, i, j + 1, obstacles);
    }
    if (i < n && j < m)
    {
        maze(s + "D", n, m, i + 1, j + 1, obstacles);
    }
}

int main()
{
    int n, m, o, u, v;
    cout << "Enter the Dimension of the matrix : ";
    cin >> n >> m;
    vector<vector<int>> obstacles(n+1, vector<int>(m+1, 0));
    cout << "Enter no. of Obstacles : ";
    cin >> o;
    cout << "Enter the Coordinates of the Obstacles : \n";
    for (int i = 0; i < o; i++)
    {
        cin >> u >> v;
        obstacles[u][v] = 1;
    }
    cout << "The Paths are : \n";
    maze("", n, m, 1, 1, obstacles);
    return 0;
}