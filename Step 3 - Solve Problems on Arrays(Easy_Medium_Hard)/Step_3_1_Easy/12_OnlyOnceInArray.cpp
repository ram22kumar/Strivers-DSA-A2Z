#include <bits/stdc++.h>
using namespace std;
int onlyOnceValue(int nums[], int n)
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
    int onlyOnceVal = onlyOnceValue(nums, n);
    cout << "This number is only once in array : " << onlyOnceVal << endl;
}