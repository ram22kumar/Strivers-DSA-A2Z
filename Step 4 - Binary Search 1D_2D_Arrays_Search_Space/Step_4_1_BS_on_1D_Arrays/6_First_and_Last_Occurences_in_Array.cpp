#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> nums, int size, int target)
{
    int low = 0, high = size - 1;
    int ans = size;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
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
pair<int, int> bruteApproach(vector<int> nums, int target)
{
    // * TC : O(N)
    // * SC : O(1)
    pair<int, int> output = {-1, -1};
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            if (output.first == -1)
            {
                output.first = i;
            }
            output.second = i;
        }
    }
    return output;
}
pair<int, int> betterApproach(vector<int> nums, int target)
{
    pair<int, int> output;
    output.first = lowerBound(nums, nums.size(), target);
    if (output.first == nums.size() || nums[output.first] != target)
    {
        return {-1, -1};
    }
    output.second = upperBound(nums, nums.size(), target) - 1;
    return output;
}
pair<int, int> optimalApproach(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    pair<int, int> output = {-1, -1};
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            output.first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (output.first == -1)
        return {-1, -1};
    low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            output.second = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return output;
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
    pair<int, int> bruteOut = bruteApproach(nums, target);
    cout << "Brute Output : " << bruteOut.first << " " << bruteOut.second << "\n";
    pair<int, int> betterOut = betterApproach(nums, target);
    cout << "Better Output: " << betterOut.first << " " << betterOut.second << "\n";
    pair<int, int> OptimalOutput = optimalApproach(nums, target);
    cout << "Optimal Output: " << OptimalOutput.first << " " << OptimalOutput.second << "\n";
}