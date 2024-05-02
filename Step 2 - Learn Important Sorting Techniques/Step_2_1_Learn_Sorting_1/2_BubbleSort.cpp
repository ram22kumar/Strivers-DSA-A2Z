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
//* 2 Loops
//* check if nextValue is greater than currentValue if yes swap them else continue moving forward
void bubbleSort(int nums[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int nums[n];
    cout << "Enter nums  : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    bubbleSort(nums, n);
    cout << "Sorted nums : ";
    printArray(nums, n);
}