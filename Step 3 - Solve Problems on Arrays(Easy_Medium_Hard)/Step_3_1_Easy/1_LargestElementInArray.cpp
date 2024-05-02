#include <bits/stdc++.h>
using namespace std;
int optimalLargestElement(int nums[], int n)
{
    int maxElement = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (maxElement < nums[i])
        {
            maxElement = nums[i];
        }
    }
    return maxElement;
}
int bruteForceLargestElement(int nums[], int n)
{
    sort(nums, nums + n);
    return nums[n - 1];
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
    cout << "Largest Elemenet in Array is : " << optimalLargestElement(nums, n) << "\n";
    cout << "Brute Force Largest Element in Array is : " << bruteForceLargestElement(nums, n) << "\n";
}