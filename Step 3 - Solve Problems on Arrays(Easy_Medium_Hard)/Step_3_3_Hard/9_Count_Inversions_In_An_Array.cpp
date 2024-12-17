#include <bits/stdc++.h>
using namespace std;
int bruteApproach(vector<int> nums, int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j])
            {
                count++;
            }
        }
    }
    return count;
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
    cout << "Brute Force Approach : ";
    cout << bruteApproach(nums, size) << endl;
}