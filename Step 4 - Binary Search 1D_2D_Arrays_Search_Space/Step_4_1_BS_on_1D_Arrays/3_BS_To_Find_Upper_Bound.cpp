#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> nums, int size, int target)
{
    int low = 0, high = size - 1;
    int ans = size;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    cout << "Enter size: ";
    int size;
    cin >> size;
    cout << "Enter nums: ";
    vector<int> nums;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int target;
    cout << "Enter target: ";
    cin >> target;
    cout << "Upper bound for " << target << " is " << upperBound(nums, size, target) << "." << endl;
}