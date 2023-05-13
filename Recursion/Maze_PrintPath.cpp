#include <bits/stdc++.h>
using namespace std;

void maze(string s, int n, int m, int i, int j)
{
    if (i == n && j == m)
    {
        cout << s << endl;
        return;
    }
    if (i < n)
    {
        maze(s + "D", n, m, i + 1, j);
    }
    if (j < m)
    {
        maze(s + "R", n, m, i, j + 1);
    }
}

int main()
{
    int n, m;
    cout << "Enter the Dimension of the matrix : ";
    cin >> n >> m;
    cout << "The Paths are : \n";
    maze("", n, m, 1, 1);
    return 0;
}