#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> arr(2);
    int n = numbers.size();
    int i = 0, j = n - 1, sum;
    while (i < j)
    {
        sum = numbers[i] + numbers[j];
        if (sum == target)
        {
            arr[0] = i + 1;
            arr[1] = j + 1;
            return arr;
        }
        else if (sum > target)
            j--;
        else
            i++;
    }
    return {-1};
}

int main()
{
    int n, target;
    cout << "Enter the no. of Elements : ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the array : \n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Enter the Target : ";
    cin >> target;
    vector<int> ans = twoSum(nums, target);
    cout << "The Indexes are : \n";
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}