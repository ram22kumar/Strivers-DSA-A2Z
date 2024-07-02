#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
vector<int> bruteApproach(vector<int> nums, int n)
{
    vector<int> output;
    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] < nums[j])
            {
                isLeader = false;
                break;
            }
        }
        if (isLeader)
        {
            output.push_back(nums[i]);
        }
    }
    return output;
}
vector<int> optimalApproach(vector<int> nums, int n)
{
    vector<int> outPut;
    outPut.push_back(nums[n - 1]);
    int maxi = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > maxi)
        {
            outPut.push_back(nums[i]);
            maxi = nums[i];
        }
    }
    return outPut;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    vector<int> nums;
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    vector<int> bruteOutput = bruteApproach(nums, n);
    cout << "Brute Output : ";
    printVector(bruteOutput);
    vector<int> optimalOutput = optimalApproach(nums, n);
    cout << "Optimal Output : ";
    printVector(optimalOutput);
}