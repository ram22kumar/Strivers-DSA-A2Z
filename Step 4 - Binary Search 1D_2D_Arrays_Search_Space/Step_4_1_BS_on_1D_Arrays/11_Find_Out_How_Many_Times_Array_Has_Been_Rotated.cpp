#include <bits/stdc++.h>
using namespace std;
int optimalApproach(vector<int> nums, int n)
{
    int low = 0, high = n;
    int output = INT_MAX;
    int indexCatcher = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[low] <= nums[high])
        {
            if (nums[low] < output)
            {
                output = nums[low];
                indexCatcher = low;
                break;
            }
        }
        if (nums[low] <= nums[mid])
        {
            if (output > nums[low])
            {
                output = nums[low];
                indexCatcher = low;
            }
            low = mid + 1;
        }
        else
        {
            if (output > nums[mid])
            {
                output = nums[mid];
                indexCatcher = mid;
            }
            high = mid - 1;
        }
    }
    return indexCatcher;
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