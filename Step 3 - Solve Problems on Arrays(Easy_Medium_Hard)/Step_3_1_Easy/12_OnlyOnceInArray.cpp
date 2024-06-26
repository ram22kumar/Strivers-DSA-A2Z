#include <bits/stdc++.h>
using namespace std;
int bruteApproach(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int val = nums[i], counter = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == val)
            {
                counter++;
            }
        }
        if (counter == 1)
        {
            return val;
        }
    }
    return -1;
}
int betterApproach(int nums[], int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    for (auto i : mp)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }
    return -1;
}
int optimalApproach(int nums[], int n)
{
    int xorVal = 0;
    for (int i = 0; i < n; i++)
    {
        xorVal ^= nums[i];
    }
    return xorVal;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    cout << "Enter nums : ";
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int bruteOnlyOnceVal = bruteApproach(nums, n);
    int betterOnlyOnceVal = betterApproach(nums, n);
    int onlyOnceVal = optimalApproach(nums, n);
    cout << "This number is only once in array brute approach   : " << bruteOnlyOnceVal << endl;
    cout << "This number is only once in array better approach  : " << betterOnlyOnceVal << endl;
    cout << "This number is only once in array optimal approach : " << onlyOnceVal << endl;
}