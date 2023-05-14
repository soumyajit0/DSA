#include <bits/stdc++.h>
using namespace std;

int knapsack01(int n, int cap, vector<int> wt, vector<int> val)
{
    if (n == 0)
    {
        if (wt[0] <= cap)
            return val[0];
        else
            return 0;
    }
    int without = knapsack01(n - 1, cap, wt, val) + 0;
    int with = 0;
    if (wt[n] <= cap)
        with = knapsack01(n - 1, cap - wt[n], wt, val) + val[n];
    return max(without, with);
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
    maxVal = knapsack01(n - 1, cap, wt, val);
    cout << "The Maximum Value : " << maxVal << endl;
    return 0;
}