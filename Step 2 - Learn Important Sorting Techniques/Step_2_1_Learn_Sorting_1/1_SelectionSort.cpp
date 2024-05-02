#include <bits/stdc++.h>
using namespace std;
void printArray(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
//* Find the minimum Number
//* Swap the values between minimum number and i value.
void selectionSort(int nums[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minNum = i;
        for (int j = i; j < n; j++)
        {
            if (nums[j] < nums[minNum])
            {
                minNum = j;
            }
        }
        int temp = nums[minNum];
        nums[minNum] = nums[i];
        nums[i] = temp;
    }
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
    selectionSort(nums, n);
    cout << "Sorted nums : ";
    printArray(nums, n);
}
