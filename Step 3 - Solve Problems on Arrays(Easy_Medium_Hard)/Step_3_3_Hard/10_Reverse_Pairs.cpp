#include <bits/stdc++.h>
using namespace std;
int bruteApproach(vector<int> nums, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] > 2 * nums[j])
            {
                count++;
            }
        }
    }
    return count;
}
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}
int countVals(vector<int> &nums, int low, int mid, int high)
{
    int count = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && nums[i] > 2 * (long long)nums[right])
        {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}
int mergeSort(vector<int> &nums, int low, int high)
{
    int count = 0;
    if (low >= high)
    {
        return count;
    }
    int mid = (low + high) / 2;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += countVals(nums, low, mid, high);
    merge(nums, low, mid, high);
    return count;
}
int optimalApproach(vector<int> &nums, int size)
{
    return mergeSort(nums, 0, size - 1);
}
int main()
{
    int size;
    cout << "Enter size : ";
    cin >> size;
    vector<int> nums;
    cout << "Enter nums : ";
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "Brute approach : ";
    cout << bruteApproach(nums, size) << endl;
    cout << "Optimal Approach : ";
    cout << optimalApproach(nums, size) << endl;
}