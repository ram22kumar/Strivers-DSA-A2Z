#include <bits/stdc++.h>
using namespace std;
void printArray(int *nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
void reverse(int nums[], int start, int end)
{
    while (start <= end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}
int *bruteForceLeftRotateArray(int nums[], int n, int d)
{
    d = d % n;
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = nums[i];
    }
    for (int i = d; i < n; i++)
    {
        nums[i - d] = nums[i];
    }
    int j = 0;
    for (int i = n - d; i < n; i++)
    {
        nums[i] = temp[j];
        j++;
    }
    return nums;
}
int *optimalLeftRotateArray(int *nums, int n, int d)
{
    d = d % n;
    reverse(nums, 0, d - 1);
    reverse(nums, d, n - 1);
    reverse(nums, 0, n - 1);
    return nums;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int nums[n];
    int bruteArrayTemp[n];
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        bruteArrayTemp[i] = nums[i];
    }
    cout << "Enter number of places to rotate : ";
    int d;
    cin >> d;
    int *bruteForceArrayLeftOutput = bruteForceLeftRotateArray(bruteArrayTemp, n, d);
    cout << "Brute Force approach Left Rotate : ";
    printArray(bruteForceArrayLeftOutput, n);

    int *optimalArrayLeftOutput = optimalLeftRotateArray(nums, n, d);
    cout << "Optimal approach Left Rotate     : ";
    printArray(optimalArrayLeftOutput, n);
}