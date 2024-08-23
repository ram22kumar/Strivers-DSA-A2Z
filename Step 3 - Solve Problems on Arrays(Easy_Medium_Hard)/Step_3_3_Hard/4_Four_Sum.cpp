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
vector<vector<int>> bruteApproach(vector<int> nums, int n)
{
    set<vector<int>> output;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        output.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(output.begin(), output.end());
    return ans;
}
vector<vector<int>> betterApproach(vector<int> nums, int n)
{
    set<vector<int>> output;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long fourth = 0 - sum;
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    output.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(output.begin(), output.end());
    return ans;
}
vector<vector<int>> optimalApproach(vector<int> nums, int n)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum < 0)
                {
                    k++;
                }
                else if (sum > 0)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    output.push_back(temp);
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
            }
        }
    }
    return output;
}
int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;
    cout << "Enter nums : ";
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << "Brute Approach output : \n";
    printVectorOfVector(bruteApproach(nums, n));
    cout << "Better Approach output : \n";
    printVectorOfVector(betterApproach(nums, n));
    cout << "Optimal Approach output : \n";
    printVectorOfVector(optimalApproach(nums, n));
}