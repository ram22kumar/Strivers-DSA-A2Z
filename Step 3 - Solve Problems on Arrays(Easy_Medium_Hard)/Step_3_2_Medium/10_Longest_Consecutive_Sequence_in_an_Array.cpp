#include <bits/stdc++.h>
using namespace std;
bool linear_search(vector<int> nums, int a)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == a)
        {
            return true;
        }
    }
    return false;
}
int bruteApproach(vector<int> nums)
{
    int n = nums.size();
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int a = nums[i];
        int count = 1;
        while (linear_search(nums, a + 1) == true)
        {
            a += 1;
            count += 1;
        }
        longest = max(count, longest);
    }
    return longest;
}
int betterApproach(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int currentCount = 0, leastSmaller = INT_MIN, longestSequence = 1;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] - 1 == leastSmaller)
        {
            currentCount += 1;
            leastSmaller = nums[i];
        }
        else if (nums[i] != leastSmaller)
        {
            currentCount = 1;
            leastSmaller = nums[i];
        }
        longestSequence = max(longestSequence, currentCount);
    }
    return longestSequence;
}
int optimalApproach(vector<int> nums)
{
    unordered_set<int> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }
    int longest = 1;
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int currentCount = 1;
            int a = it;
            while (st.find(a + 1) != st.end())
            {
                currentCount += 1;
                a += 1;
            }
            longest = max(longest, currentCount);
        }
    }
    return longest;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    cout << "Enter nums : ";
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "Brute Approach Output : " << bruteApproach(nums) << endl;
    cout << "Better Approach Output : " << betterApproach(nums) << endl;
    cout << "Optimal Approach Output : " << optimalApproach(nums);
}