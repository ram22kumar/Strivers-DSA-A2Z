#include <bits/stdc++.h>
using namespace std;
int optimalApproach(vector<int> nums, int n)
{
    int low = 1, high = n - 2;
    if (n == 1)
    {
        return 0;
    }
    if (nums[0] > nums[1])
    {
        return 0;
    }
    if (nums[n - 1] > nums[n - 2])
    {
        return n - 1;
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid] > nums[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
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
    int index = optimalApproach(nums, n);
    cout << index << " i.e., " << nums[index];
}