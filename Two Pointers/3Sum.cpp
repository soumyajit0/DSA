#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> arr;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if ((nums[i] + nums[j] + nums[k]) == 0)
            {
                arr.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[j + 1])
                    j++;
                while (k > j && nums[k] == nums[k - 1])
                    k--;
                j++;
                k--;
            }
            else if ((nums[j] + nums[k]) > (0 - nums[i]))
                k--;
            else
                j++;
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
    vector<vector<int>> ans = threeSum(nums);
    cout << "The Indexes are : \n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto it : ans[i])
            cout << it << " ";
        cout << endl;
    }
    return 0;
}