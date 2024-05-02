#include <bits/stdc++.h>
using namespace std;
int linearSearch(int nums[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == k)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter size of nums : ";
    cin >> n;
    int nums[n];
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cout << "Enter element to find : ";
    cin >> k;
    int kIndex = linearSearch(nums, n, k);
    if (kIndex == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at : " << kIndex << endl;
    }
}