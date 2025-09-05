#include <bits/stdc++.h>
using namespace std;
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
int optimalOutput(vector<int> nums, int target)
{
    pair<int, int> output = optimalApproach(nums, target);
    return output.second - output.first + 1;
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
    cout << "Number of Occurences : " << optimalOutput(nums, target);
}