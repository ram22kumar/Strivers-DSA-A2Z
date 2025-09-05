#include <bits/stdc++.h>
using namespace std;
int optimalApproach(vector<int> nums, int n)
{
    int low = 0, high = nums.size() - 1;
    int output = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        //! If the search space is already sorted then nums[low] will always be smaller in that search space.
        if (nums[low] <= nums[high])
        {
            output = min(output, nums[low]);
            break;
        }

        if (nums[low] <= nums[mid])
        {
            output = min(output, nums[low]);
            low = mid + 1;
        }
        else
        {
            output = min(output, nums[mid]);
            high = mid - 1;
        }
    }
    return output;
}
int main()
{
    int n;
    cout << "Enter nums size : ";
    cin >> n;
    cout << "Enter nums : ";
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << optimalApproach(nums, n);
}