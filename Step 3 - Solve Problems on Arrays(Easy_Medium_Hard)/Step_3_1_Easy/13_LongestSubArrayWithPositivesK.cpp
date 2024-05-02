#include <bits/stdc++.h>
using namespace std;
int naiveBruteForce(int nums[], int n, int k)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long s = 0;
            for (int k = i; k <= j; k++)
            {
                s += nums[k];
            }
            if (s == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}
int bruteForce(int nums[], int n, int k)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        long long s = 0;
        for (int j = i; j < n; j++)
        {
            s += nums[i];
            if (s == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}
int betterApproachHashing(int nums[], int n, int k)
{
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
int optimalApproach2Pointer(int nums[], int n, int k)
{
    int left = 0, right = 0;
    int maxLen = 0;
    int sum = nums[0];
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= nums[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += nums[right];
        }
    }
    return maxLen;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int k;
    cout << "Enter k : ";
    cin >> k;
    int nums[n];
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Naive Brute Force : " << naiveBruteForce(nums, n, k) << endl;
    cout << "Brute Force : " << bruteForce(nums, n, k) << endl;
    cout << "Better with Hashing : " << betterApproachHashing(nums, n, k) << endl;
    cout << "Optimal Approach with 2 pointers : " << optimalApproach2Pointer(nums, n, k) << endl;
}