#include <bits/stdc++.h>
using namespace std;
int iterativeBinarySearch(vector<int> nums, int size, int target)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int recursiveBinarySearch(vector<int> nums, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }
    else if (nums[mid] > target)
    {
        return recursiveBinarySearch(nums, low, mid - 1, target);
    }
    return recursiveBinarySearch(nums, mid + 1, high, target);
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
    int targetIndex = iterativeBinarySearch(nums, size, target);
    if (targetIndex != -1)
    {
        cout << nums[targetIndex] << " is found at " << targetIndex << ".\n";
    }
    else
    {
        cout << target << " can't be found in the array." << endl;
    }
    int recursiveTargetIndex = recursiveBinarySearch(nums, 0, size, target);
    if (recursiveTargetIndex != -1)
    {
        cout << nums[recursiveTargetIndex] << " is found at " << recursiveTargetIndex << ".\n";
    }
    else
    {
        cout << target << " can't be found in the array." << endl;
    }
}