#include <bits/stdc++.h>
using namespace std;
int findMissingNumberBruteApproach(int nums[], int n)
{
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (nums[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            flag = i;
            break;
        }
    }
    return flag;
}
int findMissingNumberBetterApproach(int nums[], int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n - 1; i++)
    {
        hash[nums[i]]++;
    }
    int val = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (hash[i] == 0)
        {
            val = i;
            break;
        }
    }
    return val;
}
int findMissingNumberOptimalApproach(int nums[], int n)
{
    // Sum Approach
    int sumN = (n * (n + 1)) / 2;
    int sumNums = 0;
    for (int i = 0; i < n - 1; i++)
        sumNums += nums[i];
    cout << "Sum Approach : " << sumN - sumNums << endl;
    // XOR Approach
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor1 = xor1 ^ (i + 1);
        xor2 = xor2 ^ nums[i];
    }
    xor1 ^= n;
    return (xor2 ^ xor1);
}
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    int nums[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> nums[i];
    }
    int bruteOutput = findMissingNumberBruteApproach(nums, n);
    cout << "Brute force output : " << bruteOutput << endl;
    int betterOutput = findMissingNumberBetterApproach(nums, n);
    cout << "Better force output : " << betterOutput << endl;
    int optimalOutput = findMissingNumberOptimalApproach(nums, n);
    cout << "Better force output : " << optimalOutput << endl;
}