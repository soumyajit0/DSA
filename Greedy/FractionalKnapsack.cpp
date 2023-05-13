#include <bits/stdc++.h>
using namespace std;

double knapsack(int n, vector<double> wt, vector<double> val, int capacity)
{
    vector<double> val_wt(n), quantity(n, 0);
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        val_wt[i] = val[i] / wt[i];
    }
    double knapsackWt = 0, knapsackVal = 0;
    int count = 0;
    while (count < n && knapsackWt < capacity)
    {
        int index = -1;
        double max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && val_wt[i] > max)
            {
                index = i;
                max = val_wt[i];
            }
        }
        vis[index] = 1;
        if ((wt[index] + knapsackWt) <= capacity)
        {
            knapsackWt += wt[index];
            quantity[index] = wt[index];
            knapsackVal += val[index];
        }
        else
        {
            knapsackVal += (capacity - knapsackWt) / wt[index] * val[index];
            quantity[index] = (capacity - knapsackWt);
            knapsackWt = capacity;
        }
        count++;
    }
    cout << "The Solution Vector is : \n";
    for (int i = 0; i < n; i++)
    {
        if (!quantity[i])
            continue;
        cout << quantity[i] << " ";
    }
    cout << endl;
    return knapsackVal;
}

int main()
{
    int n, capacity;
    cout << "Enter the no. of Items : ";
    cin >> n;
    vector<double> wt(n), val(n);
    cout << "Enter the Weights and Values : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    cout << "Enter the Knapsack Capacity : ";
    cin >> capacity;
    double ans = knapsack(n, wt, val, capacity);
    cout << "Maxium Value : " << fixed << setprecision(2) << ans << endl;
    return 0;
}