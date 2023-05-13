#include <bits/stdc++.h>
using namespace std;

void maze(string s, int n, int m, int i, int j, vector<vector<int>> &matrix, vector<vector<int>> path, int step)
{
    if (i == n && j == m)
    {
        path[i][j] = step;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        cout << s << endl
             << endl;
        return;
    }
    if (matrix[i][j])
    {
        return;
    }
    matrix[i][j] = 1;
    path[i][j] = step;
    if (i > 1)
    {
        maze(s + "U", n, m, i - 1, j, matrix, path, step + 1);
    }
    if (j > 1)
    {
        maze(s + "L", n, m, i, j - 1, matrix, path, step + 1);
    }
    if (i < n)
    {
        maze(s + "D", n, m, i + 1, j, matrix, path, step + 1);
    }
    if (j < m)
    {
        maze(s + "R", n, m, i, j + 1, matrix, path, step + 1);
    }
    matrix[i][j] = 0;
    path[i][j] = 0;
}

int main()
{
    int n, m;
    cout << "Enter the Dimension of the matrix : ";
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> path(n + 1, vector<int>(m + 1, 0));
    cout << "The Paths are : \n";
    maze("", n, m, 1, 1, matrix, path, 1);
    return 0;
}