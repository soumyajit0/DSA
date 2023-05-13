#include <bits/stdc++.h>
using namespace std;

void maze(string s, int n, int m, int i, int j, vector<vector<int>> &matrix)
{
    if (i == n && j == m)
    {
        cout << s << endl;
        return;
    }
    if (matrix[i][j])
    {
        return;
    }
    matrix[i][j] = 1;
    if (i > 1)
    {
        maze(s + "U", n, m, i - 1, j, matrix);
    }
    if (j > 1)
    {
        maze(s + "L", n, m, i, j - 1, matrix);
    }
    if (i < n)
    {
        maze(s + "D", n, m, i + 1, j, matrix);
    }
    if (j < m)
    {
        maze(s + "R", n, m, i, j + 1, matrix);
    }
    matrix[i][j] = 0;
}

int main()
{
    int n, m;
    cout << "Enter the Dimension of the matrix : ";
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    cout << "The Paths are : \n";
    maze("", n, m, 1, 1, matrix);
    return 0;
}