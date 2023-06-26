#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> arr;
    int n = nums.size();
    for (int l = 0; l < n - 3; l++)
    {
        if (l > 0 && nums[l] == nums[l - 1])
            continue;

        for (int i = l + 1; i < n - 2; i++)
        {
            if (i > l + 1 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                long long int sum = nums[l] + nums[i];
                sum += nums[j];
                sum += nums[k];
                if (sum == target)
                {
                    arr.push_back({nums[l], nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (k > j && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }
                else if (sum > target)
                    k--;
                else
                    j++;
            }
        }
    }
    return arr;
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
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The Indexes are : \n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto it : ans[i])
            cout << it << " ";
        cout << endl;
    }
    return 0;
}