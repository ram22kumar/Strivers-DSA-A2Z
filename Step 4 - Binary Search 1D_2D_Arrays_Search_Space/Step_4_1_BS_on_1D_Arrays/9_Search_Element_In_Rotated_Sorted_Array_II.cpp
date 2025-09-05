#include <bits/stdc++.h>
using namespace std;
int searchInSortedArrayII(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return 1;
        }
        if (nums[mid] == nums[low] && nums[mid] == nums[high])
        {
            low++;
            high--;
            continue;
        }
        // left is sorted;
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
        // right is sorted;
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
    cout << "Enter nums : ";
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int target;
    cout << "Enter target : ";
    cin >> target;
    if (searchInSortedArrayII(nums, target) == 1)
    {
        cout << "Target is present\n";
    }
    else
    {
        cout << "Target is absent\n";
    }
}