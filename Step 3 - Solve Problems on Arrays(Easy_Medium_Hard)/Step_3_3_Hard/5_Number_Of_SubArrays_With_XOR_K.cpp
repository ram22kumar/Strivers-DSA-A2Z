#include <bits/stdc++.h>
using namespace std;
int bruteApproach(vector<int> nums, int n, int target)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xorVal = 0;
            for (int k = i; k <= j; k++)
            {
                xorVal ^= nums[k];
            }
            if (xorVal == target)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int betterApproach(vector<int> nums, int n, int target)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int xorVal = 0;
        for (int j = i; j < n; j++)
        {
            xorVal ^= nums[j];
            if (xorVal == target)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int optimalApproach(vector<int> nums, int n, int target)
{
    int xr = 0;
    map<int, int> mp;
    mp[xr]++;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= nums[i];
        int x = xr ^ target;
        cnt += mp[x];
        mp[xr]++;
    }
    return cnt;
}
int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;
    cout << "Enter nums : ";
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << "Enter target : ";
    int target;
    cin >> target;
    cout << "Brute Approach Output : ";
    cout << bruteApproach(nums, n, target) << endl;
    cout << "Better Approach Output : ";
    cout << betterApproach(nums, n, target) << endl;
    cout << "Optimal Approach Output : ";
    cout << optimalApproach(nums, n, target) << endl;
}