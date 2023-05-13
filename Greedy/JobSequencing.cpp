#include <bits/stdc++.h>
using namespace std;

int jobSequencing(int n, int maxDeadline, vector<int> profit, vector<int> deadline, vector<int> &slot)
{
    vector<int> fixed(n, 0);
    int totalProfit = 0;
    for (int count = 0; count < n; count++)
    {
        int max = INT_MIN, index = -1;
        for (int i = 0; i < n; i++)
        {
            if (!fixed[i] && max < profit[i])
            {
                index = i;
                max = profit[i];
            }
        }
        fixed[index] = 1;
        for (int i = deadline[index] - 1; i >= 0; i--)
        {
            if (slot[i] == INT_MIN)
            {
                slot[i] = index + 1;
                totalProfit += profit[index];
                break;
            }
        }
    }
    return totalProfit;
}

void displaySlot(int maxDeadline, vector<int> slot)
{
    for (int i = 0; i < maxDeadline; i++)
    {
        if (slot[i] == INT_MIN)
            continue;
        cout << "Slot " << i + 1 << " booked for Job " << slot[i] << endl;
    }
}

int main()
{
    int n, maxDeadline = INT_MIN, totalProfit;
    cout << "Enter no. of Jobs : ";
    cin >> n;
    vector<int> profit(n), deadline(n);
    cout << "Enter the Job's Profit and Deadline : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i] >> deadline[i];
        if (maxDeadline < deadline[i])
        {
            maxDeadline = deadline[i];
        }
    }
    vector<int> slot(maxDeadline, INT_MIN);
    totalProfit = jobSequencing(n, maxDeadline, profit, deadline, slot);
    cout << "Total Profit : " << totalProfit << endl;
    displaySlot(maxDeadline, slot);
    return 0;
}