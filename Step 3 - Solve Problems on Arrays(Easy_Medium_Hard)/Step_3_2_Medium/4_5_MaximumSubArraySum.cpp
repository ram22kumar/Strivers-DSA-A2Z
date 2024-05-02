#include <bits/stdc++.h>
using namespace std;
int bruteApproach(int nums[], int n)
{
    int sum, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += nums[k];
            }
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}
int betterApproach(int nums[], int n)
{
    int sum, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}
int optimalApproach(int nums[], int n)
{
    int sum = 0, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (maxi < sum)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}
int followUpOptimalApproach(int nums[], int n)
{
    int sum = 0, maxi = INT_MIN, ansStart = -1, ansEnd = -1, start;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += nums[i];
        if (maxi < sum)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int nums[n];
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