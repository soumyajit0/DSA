#include <bits/stdc++.h>
using namespace std;

int MCM(vector<int> arr, int i, int j, vector<vector<int>> dp)
{
    if (i + 1 == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, MCM(arr, i, k, dp) + MCM(arr, k, j, dp) + arr[i] * arr[k] * arr[j]);
    }
    dp[i][j] = res;
    return res;
}

int main()
{
    int n;
    cout << "Enter the no. of Matrices : ";
    cin >> n;
    vector<int> arr(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << "Enter the Dimensions of the Matrices : ";
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << "The Minimum No. of Operations : " << MCM(arr, 0, n, dp) << endl;
    return 0;
}