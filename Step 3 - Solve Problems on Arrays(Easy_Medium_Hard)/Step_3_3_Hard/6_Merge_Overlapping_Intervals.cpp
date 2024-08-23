#include <bits/stdc++.h>
using namespace std;
void printVectorOfVector(vector<vector<int>> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> bruteApproach(vector<vector<int>> intervals, int n)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}
vector<vector<int>> optimalApproach(vector<vector<int>> intervals, int n)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}
int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;
    cout << "Enter intervals : ";
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        intervals.push_back({temp1, temp2});
    }
    cout << "Brute Approach : " << endl;
    printVectorOfVector(bruteApproach(intervals, n));
    cout << "Optimal Approach : " << endl;
    printVectorOfVector(optimalApproach(intervals, n));
}