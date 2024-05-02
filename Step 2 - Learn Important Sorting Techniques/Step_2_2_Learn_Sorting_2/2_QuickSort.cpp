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
int partitionFinder(int nums[], int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high;
    while (i < j)
    {
        while (nums[i] <= nums[pivot] && i <= high)
        {
            i++;
        }
        while (nums[j] > nums[pivot] && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    int temp2 = nums[low];
    nums[low] = nums[j];
    nums[j] = temp2;
    return j;
}
void quickSort(int nums[], int low, int high)
{
    if (low < high)
    {
        int partitionerIndex = partitionFinder(nums, low, high);
        quickSort(nums, low, partitionerIndex - 1);
        quickSort(nums, partitionerIndex + 1, high);
    }
}
int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;
    cout << "Enter nums  : ";
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    quickSort(nums, 0, n - 1);
    cout << "Sorted nums : ";
    printArray(nums, n);
}