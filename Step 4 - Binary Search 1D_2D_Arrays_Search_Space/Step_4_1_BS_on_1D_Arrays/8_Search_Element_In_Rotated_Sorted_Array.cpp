#include <bits/stdc++.h>
using namespace std;
int searchInSortedArray(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // if left is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // if right is sorted
        else
        {
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> nums;
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int target;
    cout << "Enter target : ";
    cin >> target;
    cout << searchInSortedArray(nums, target);
}