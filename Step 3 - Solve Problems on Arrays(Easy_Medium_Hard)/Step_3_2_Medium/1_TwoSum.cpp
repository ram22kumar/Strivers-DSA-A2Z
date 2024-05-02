#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> bruteForceApproach(int nums[], int n, int target)
{
    vector<pair<int, int>> output;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                output.push_back({nums[i], nums[j]});
            }
        }
    }
    return output;
}
vector<pair<int, int>> betterApproach(int nums[], int n, int target)
{
    map<int, int> mp;
    vector<pair<int, int>> output;
    for (int i = 0; i < n; i++)
    {
        int neededVal = target - nums[i];
        if (mp.find(neededVal) != mp.end())
        {
            output.push_back({neededVal, nums[i]});
        }
        mp[nums[i]] = i;
    }
    return output;
}
vector<pair<int, int>> optimalApproach(int nums[], int n, int target)
{
    vector<pair<int, int>> output;
    sort(nums, nums + n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sumVal = nums[i] + nums[j];
        if (sumVal == target)
        {
            output.push_back({nums[i], nums[j]});
            i++;
            j--;
        }
        else if (sumVal > target)
        {
            j--;
        }
        else if (sumVal < target)
        {
            i++;
        }
    }
    return output;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int target;
    cout << "Enter target : ";
    cin >> target;
    int nums[n];
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<pair<int, int>> bruteApproach = bruteForceApproach(nums, n, target);
    cout << "Brute Force Approach : " << endl;
    for (pair<int, int> i : bruteApproach)
        cout << i.first << " " << i.second << endl;
    vector<pair<int, int>> betterApproachOutput = betterApproach(nums, n, target);
    cout << "Better Approach : " << endl;
    for (pair<int, int> i : betterApproachOutput)
        cout << i.first << " " << i.second << endl;
    vector<pair<int, int>> optimalApproachOutput = optimalApproach(nums, n, target);
    cout << "Optimal Approach : " << endl;
    for (pair<int, int> i : optimalApproachOutput)
        cout << i.first << " " << i.second << endl;
}