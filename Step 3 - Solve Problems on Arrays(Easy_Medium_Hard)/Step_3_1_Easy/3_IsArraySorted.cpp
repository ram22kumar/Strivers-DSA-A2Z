#include <bits/stdc++.h>
using namespace std;
bool isArraySorted(int nums[], int n)
{
    if (n < 2)
    {
        return INT_MIN;
    }
    int isIncreasing = false;
    if (nums[0] < nums[1])
    {
        isIncreasing = true;
    }
    for (int i = 1; i < n; i++)
    {
        if ((isIncreasing == true && nums[i] >= nums[i - 1]) || (isIncreasing == false && nums[i] < nums[i - 1]))
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;
    int nums[n];
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (isArraySorted(nums, n))
    {
        cout << "Yes the Array is sorted" << endl;
    }
    else
    {
        cout << "No the Array is not sorted" << endl;
    }
}