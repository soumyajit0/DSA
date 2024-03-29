#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hashmap;
    vector<int> ans(2);
    for (int i = 0; i < nums.size(); i++)
        hashmap[nums[i]] = i;
    for (int i = 0; i < nums.size(); i++)
    {
        if (hashmap.count(target - nums[i]) && hashmap.find(target - nums[i])->second != i)
        {
            ans[0] = i;
            ans[1] = hashmap.find(target - nums[i])->second;
        }
    }
    return ans;
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