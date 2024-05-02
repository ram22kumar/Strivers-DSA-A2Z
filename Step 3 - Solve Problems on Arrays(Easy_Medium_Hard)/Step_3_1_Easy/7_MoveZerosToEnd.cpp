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
void printVector(vector<int> nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
vector<int> bruteMoveZerosToEnd(int nums[], int n)
{
    vector<int> out;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            out.push_back(nums[i]);
        }
    }
    for (int i = out.size(); i < n; i++)
    {
        out.push_back(0);
    }
    return out;
}
int *optimalApproachMoveZerosToEnd(int nums[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < n; i++)
    {
        if (nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            j++;
            nums[j] = temp;
        }
    }
    return nums;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    cout << "Enter nums : ";
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> out = bruteMoveZerosToEnd(nums, n);
    cout << "Vector : ";
    printVector(out, out.size());
    int *optimalOutput = optimalApproachMoveZerosToEnd(nums, n);
    cout << "Output : ";
    printArray(optimalOutput, n);
}