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
int *optimalRotateArray(int *nums, int n)
{
    // * Only Optimal approach no Brute approach required as this can be treated as optimal
    int temp = nums[0];
    for (int i = 1; i < n; i++)
    {
        nums[i - 1] = nums[i];
    }
    nums[n - 1] = temp;
    return nums;
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
    int *bruteArrayOutput = optimalRotateArray(nums, n);
    cout << "Optimal approach : ";
    printArray(bruteArrayOutput, n);
}