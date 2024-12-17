#include <bits/stdc++.h>
using namespace std;
void bruteApproach(vector<int> nums, int n)
{
    int repeated = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
            {
                count++;
            }
        }
        if (count == 0)
        {
            missing = i;
        }
        else if (count == 2)
        {
            repeated = i;
        }

        if (missing != -1 && repeated != -1)
        {
            break;
        }
    }
    cout << repeated << " is repeating" << endl;
    cout << missing << " is missing" << endl;
}
void betterApproach(vector<int> nums, int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }

    int repeated = -1, missing = -1;
    for (int i = 1; i < n + 1; i++)
    {
        if (hash[i] == 0)
        {
            missing = i;
        }
        else if (hash[i] == 2)
        {
            repeated = i;
        }
    }
    cout << repeated << " is repeating" << endl;
    cout << missing << " is missing" << endl;
}
void optimalApproach1(vector<int> nums, int size)
{
    long long n = nums.size();
    long long S = 0, SN, S2 = 0, S2N;
    SN = (n * (n + 1)) / 2;
    S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    for (int i = 0; i < n; i++)
    {
        S += nums[i];
        S2 += (long long)(nums[i]) * (long long)(nums[i]);
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    cout << x << " is repeating" << endl;
    cout << y << " is missing" << endl;
}
void optimalApproach2(vector<int> nums, int size)
{
    int xr = 0;
    for (int i = 0; i < size; i++)
    {
        xr ^= nums[i];
        xr ^= (i + 1);
    }
    int bitNo = (xr & ~(xr - 1));

    int zero = 0, one = 0;
    for (int i = 0; i < size; i++)
    {
        if ((nums[i] & bitNo) != 0)
        {
            one ^= nums[i];
        }
        else
        {
            zero ^= nums[i];
        }
    }
    for (int i = 1; i <= size; i++)
    {
        if ((i & bitNo) != 0)
        {
            one = one ^ i;
        }
        else
        {
            zero = zero ^ i;
        }
    }
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == zero)
            count++;
    }
    if (count == 2)
    {
        cout << zero << " is repeating" << endl;
        cout << one << " is missing" << endl;
    }
    else
    {
        cout << one << " is repeating" << endl;
        cout << zero << " is missing" << endl;
    }
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
    cout << "Brute Force : \n";
    bruteApproach(nums, n);
    cout << "Optimal 1 Approach : \n";
    optimalApproach1(nums, n);
    cout << "Optimal 2 Approach : \n";
    optimalApproach2(nums, n);
}