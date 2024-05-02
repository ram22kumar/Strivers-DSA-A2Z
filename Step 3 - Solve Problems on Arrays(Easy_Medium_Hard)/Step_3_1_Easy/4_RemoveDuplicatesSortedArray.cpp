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
int bruteForceRemoveDuplicates(int nums[], int n)
{
    set<int> uniqSet;
    for (int i = 0; i < n; i++)
    {
        uniqSet.insert(nums[i]);
    }
    int setSize = uniqSet.size();
    int j = 0;
    for (int i : uniqSet)
    {
        nums[j] = i;
        j++;
    }
    return setSize;
}
int optimalRemoveDuplicates(int nums[], int n)
{
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (nums[i] == nums[j])
        {
            j++;
        }
        else if (nums[i] != nums[j])
        {
            int temp = nums[i + 1];
            nums[i + 1] = nums[j];
            nums[j] = temp;
            i++;
            j++;
        }
    }
    return i + 1;
}
int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;
    int nums[n], bruteNums[n], optimalNums[n];
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        bruteNums[i] = nums[i];
        optimalNums[i] = nums[i];
    }
    cout << "Brute Force Approach : ";
    int newBruteSize = bruteForceRemoveDuplicates(bruteNums, n);
    printArray(bruteNums, newBruteSize);
    cout << "Optimal Approach : ";
    int newOptimalSize = optimalRemoveDuplicates(optimalNums, n);
    printArray(optimalNums, newOptimalSize);
}