#include <bits/stdc++.h>
using namespace std;
int bruteApproach(vector<int> nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int product = 1;
            for (int k = i; k <= j; k++)
            {
                product *= nums[k];
            }
            maxi = max(maxi, product);
        }
    }
    return maxi;
}
int betterApproach(vector<int> nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= nums[j];
            maxi = max(maxi, product);
        }
    }
    return maxi;
}
int optimalApproach(vector<int> nums)
{
    int n = nums.size();
    int prefix = 1, suffix = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix *= nums[i];
        suffix *= nums[n - i - 1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}
int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter nums: ";
    vector<int> nums;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << "Brute Approach Output: " << bruteApproach(nums) << endl;
    cout << "Better Approach Output: " << betterApproach(nums) << endl;
    cout << "Optimal Approach Output: " << optimalApproach(nums) << endl;
}