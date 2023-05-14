#include <bits/stdc++.h>
using namespace std;

int knapsack01(int n, int cap, vector<int> wt, vector<int> val, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (wt[0] <= cap)
            return val[0];
        return 0;
    }
    if (dp[n][cap] != -1)
        return dp[n][cap];
    int without = knapsack01(n - 1, cap, wt, val, dp) + 0;
    int with = 0;
    if (wt[n] <= cap)
        with = knapsack01(n - 1, cap - wt[n], wt, val, dp) + val[n];
    return dp[n][cap] = max(without, with);
}

int main()
{
    int n, cap, maxVal;
    cout << "Enter the no. of elements : ";
    cin >> n;
    vector<int> wt(n), val(n);
    cout << "Enter the weights and values of the items : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    cout << "Enter the Knapsack Capacity : ";
    cin >> cap;
    vector<vector<int>> dp(n, vector<int>(cap + 1, -1));
    maxVal = knapsack01(n - 1, cap, wt, val, dp);
    cout << "The Maximum Value : " << maxVal << endl;
    return 0;
}