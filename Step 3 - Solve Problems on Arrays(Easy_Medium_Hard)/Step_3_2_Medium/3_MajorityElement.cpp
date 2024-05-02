#include <bits/stdc++.h>
using namespace std;
int bruteApproach(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            return nums[i];
        }
    }
    return -1;
}
int betterApproach(int nums[], int n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }
    for (int i = 0; i < mpp.size(); i++)
    {
        if (mpp[i] > n / 2)
        {
            return i;
        }
    }
    return -1;
}
//! Moore's Voting Algorithm
//* TC: O(N) SC : O(1)
int optimalApproach(int nums[], int n)
{
    int element = nums[0], count = 0;
    for (int i = 1; i < n; i++)
    {
        if (count == 0)
        {
            element = nums[i];
            count = 1;
        }
        if (nums[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (element == nums[i])
        {
            count1++;
        }
    }
    if (count1 > (n / 2))
    {
        return element;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int nums[n];
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int bruteOutput = bruteApproach(nums, n);
    cout << "Brute Approach Output   : " << bruteOutput << endl;
    int betterOutput = betterApproach(nums, n);
    cout << "Better Approach Output  : " << betterOutput << endl;
    int optimalOutput = optimalApproach(nums, n);
    cout << "Optimal Approach Output : " << optimalOutput << endl;
}