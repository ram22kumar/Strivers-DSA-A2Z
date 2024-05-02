#include <bits/stdc++.h>
using namespace std;
void printArray(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}
// * Take an element
// * Place it in its correct order
void insertionSort(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && nums[j - 1] > nums[j])
        {
            int temp = nums[j - 1];
            nums[j - 1] = nums[j];
            nums[j] = temp;
            j--;
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
    insertionSort(nums, n);
    cout << "Sorted nums : ";
    printArray(nums, n);
}