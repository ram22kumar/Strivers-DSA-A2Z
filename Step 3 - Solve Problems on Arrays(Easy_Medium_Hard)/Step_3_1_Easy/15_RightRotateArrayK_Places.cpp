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
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
int *bruteForceRightRotateArray(int *nums, int n, int d)
{
    d = d % n;
    int temp[d];
    for (int i = n - d; i < n; i++)
    {
        temp[i - n + d] = nums[i];
    }
    for (int i = n - d - 1; i >= 0; i--)
    {
        nums[i + d] = nums[i];
    }
    for (int i = 0; i < d; i++)
    {
        nums[i] = temp[i];
    }
    return nums;
}
int *optimalRightRotateArray(int nums[], int n, int d)
{
    d = d % n;
    reverse(nums, 0, n - d - 1);
    reverse(nums, n - d, n - 1);
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
    int *bruteForceArrayRightOutput = bruteForceRightRotateArray(bruteArrayTemp, n, d);
    cout << "Brute Force approach Right Rotate : ";
    printArray(bruteForceArrayRightOutput, n);

    int *optimalArrayRightOutput = optimalRightRotateArray(nums, n, d);
    cout << "Optimal approach Right Rotate     : ";
    printArray(optimalArrayRightOutput, n);
}