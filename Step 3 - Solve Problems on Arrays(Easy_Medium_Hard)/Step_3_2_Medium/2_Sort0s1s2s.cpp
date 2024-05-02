#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> output)
{
    for (int i : output)
    {
        cout << i << " ";
    }
    cout << endl;
}
vector<int> bruteApproach(int nums[], int n)
{
    vector<int> output(nums, nums + n);
    sort(output.begin(), output.end());
    return output;
}
vector<int> betterApproach(int nums[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    vector<int> output(nums, nums + n);
    for (int i = 0; i < n; i++)
    {
        if (output[i] == 0)
        {
            count0++;
        }
        else if (output[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    int i = 0;
    while (count0 > 0)
    {
        output[i] = 0;
        count0--;
        i++;
    }
    while (count1 > 0)
    {
        output[i] = 1;
        count1--;
        i++;
    }
    while (count2 > 0)
    {
        output[i] = 2;
        count2--;
        i++;
    }
    return output;
}
// Optimal Solution => Dutch National Flag Algorithm
vector<int> optimalDutchNationalFlag(int nums[], int n)
{
    vector<int> output(nums, nums + n);
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (output[mid] == 0)
        {
            swap(output[low], output[mid]);
            mid++;
            low++;
        }
        else if (output[mid] == 1)
        {
            mid++;
        }
        else if (output[mid] == 2)
        {
            swap(output[mid], output[high]);
            high--;
        }
    }
    return output;
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
    vector<int> bruteOutput = bruteApproach(nums, n);
    cout << "Brute Output   : ";
    printVector(bruteOutput);
    vector<int> betterOutput = betterApproach(nums, n);
    cout << "Better Output  : ";
    printVector(betterOutput);
    vector<int> optimalOutput = optimalDutchNationalFlag(nums, n);
    cout << "Optimal Output : ";
    printVector(optimalOutput);
}