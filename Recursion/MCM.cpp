#include <bits/stdc++.h>
using namespace std;

int MCM(vector<int> arr, int i, int j)
{
    if (i + 1 == j)
        return 0;
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, MCM(arr, i, k) + MCM(arr, k, j) + arr[i] * arr[k] * arr[j]);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter the no. of Matrices : ";
    cin >> n;
    vector<int> arr(n + 1);
    cout << "Enter the Dimensions of the Matrices : ";
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << "The Minimum No. of Operations : " << MCM(arr, 0, n) << endl;
    return 0;
}