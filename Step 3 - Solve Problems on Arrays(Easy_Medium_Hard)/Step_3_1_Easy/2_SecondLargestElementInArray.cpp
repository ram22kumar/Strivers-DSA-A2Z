#include <bits/stdc++.h>
using namespace std;
int bruteSecondLargestElement(int nums[], int n)
{
    // ! TC : O(N*Log(N) + N)
    // ! SC : O(1)
    sort(nums, nums + n);
    int secondLargest = INT_MIN;
    int largest = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] != largest)
        {
            secondLargest = nums[i];
            break;
        }
    }
    return secondLargest;
}
int betterSecondLargestElement(int nums[], int n)
{
    // ! TC : O(N+N) = O(2N)
    int secondLargest = INT_MIN;
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > largest)
        {
            largest = nums[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > secondLargest && nums[i] < largest)
        {
            secondLargest = nums[i];
        }
    }
    return secondLargest;
}
int optimalSecondLargestElement(int nums[], int n)
{
    // ! TC : O(N)
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > largest)
        {
            secondLargest = largest;
            largest = nums[i];
        }
        else if (nums[i] > secondLargest && nums[i] < largest)
        {
            secondLargest = nums[i];
        }
    }
    return secondLargest;
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
    cout << "Second Largest Element in Array with brute force approach is : " << bruteSecondLargestElement(nums, n) << "\n";
    cout << "Second Largest Element in Array with better approach is : " << betterSecondLargestElement(nums, n) << "\n";
    cout << "Second Largest Element in Array with optimal approach is : " << optimalSecondLargestElement(nums, n) << "\n";
}