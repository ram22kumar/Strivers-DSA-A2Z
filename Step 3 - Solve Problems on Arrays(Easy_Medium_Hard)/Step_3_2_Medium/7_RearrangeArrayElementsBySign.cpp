#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
vector<int> bruteApproach(int nums[], int n)
{
    vector<int> positiveArray;
    vector<int> negativeArray;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            positiveArray.push_back(nums[i]);
        }
        else
        {
            negativeArray.push_back(nums[i]);
        }
    }
    vector<int> output;
    int i = 0;
    while (i < positiveArray.size())
    {
        output.push_back(positiveArray[i]);
        output.push_back(negativeArray[i]);
        i++;
    }
    return output;
}
vector<int> optimalApproach(int nums[], int n)
{
    vector<int> output(n, 0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            output[posIndex] = nums[i];
            posIndex += 2;
        }
        else
        {
            output[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return output;
}
vector<int> optimalRearrangeArrayDifferentNumberOfSignedElements(int nums[], int n)
{
    vector<int> posNums, negNums;
    vector<int> outputNums(n);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            posNums.push_back(nums[i]);
        }
        else
        {
            negNums.push_back(nums[i]);
        }
    }
    if (posNums.size() > negNums.size())
    {
        for (int i = 0; i < negNums.size(); i++)
        {
            outputNums.push_back(posNums[i]);
            outputNums.push_back(negNums[i]);
        }
        for (int i = negNums.size(); i < posNums.size(); i++)
        {
            outputNums.push_back(posNums[i]);
        }
    }
    else
    {
        for (int i = 0; i < posNums.size(); i++)
        {
            outputNums.push_back(posNums[i]);
            outputNums.push_back(negNums[i]);
        }
        for (int i = posNums.size(); i < negNums.size(); i++)
        {
            outputNums.push_back(posNums[i]);
        }
    }
    return outputNums;
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
    vector<int> bruteOutput = bruteApproach(nums, n);
    cout << "Brute output   : ";
    printVector(bruteOutput, bruteOutput.size());
    vector<int> optimalOutput = optimalApproach(nums, n);
    cout << "optimal output : ";
    printVector(optimalOutput, optimalOutput.size());
}