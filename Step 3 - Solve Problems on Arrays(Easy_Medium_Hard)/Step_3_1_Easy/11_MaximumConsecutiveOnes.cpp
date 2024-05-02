#include <bits/stdc++.h>
using namespace std;
int maximumConsecutiveOnes(int nums[], int n)
{
    int consequtiveOnes = 0;
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            consequtiveOnes++;
            maxLength = max(maxLength, consequtiveOnes);
        }
        else
        {
            consequtiveOnes = 0;
        }
    }
    return maxLength;
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
    int maxOnes = maximumConsecutiveOnes(nums, n);
    cout << "Maximum consecutive ones : " << maxOnes << endl;
}