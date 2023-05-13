#include <bits/stdc++.h>
using namespace std;

int maze(int n, int m, int i, int j)
{
    if (i == n || j == m)
    {
        return 1;
    }
    return maze(n, m, i + 1, j) + maze(n, m, i, j + 1);
}

int main()
{
    int n, m;
    cout << "Enter the Dimension of the matrix : ";
    cin >> n >> m;
    cout << "No. of Paths to reach the last Cell : " << maze(n, m, 1, 1) << endl;
    return 0;
}