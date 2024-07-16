#include <bits/stdc++.h>
using namespace std;
int optimalApproach(vector<int> nums, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        preSum += nums[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}
int main()
{
    int n;
    cout << "Enter n : ";
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
    int k;
    cin >> k;
    int output = optimalApproach(nums, k);
    cout << "Number of Subarrays with sum " << k << " is : " << output;
}