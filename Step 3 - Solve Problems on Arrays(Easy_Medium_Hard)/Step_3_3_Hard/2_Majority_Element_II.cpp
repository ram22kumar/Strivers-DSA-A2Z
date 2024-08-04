#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
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
        if (output.size() == 0 || output[0] != nums[i])
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    count++;
                }
            }
            if (count > n / 3)
            {
                output.push_back(nums[i]);
            }
            if (output.size() == 2)
            {
                break;
            }
        }
    }
    return output;
}
vector<int> betterApproach(vector<int> nums, int n)
{
    map<int, int> mp;
    vector<int> out;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
        if (mp[nums[i]] == (n / 3) + 1)
        {
            out.push_back(nums[i]);
        }
    }
    return out;
}
vector<int> optimnalApproach(vector<int> nums, int n)
{
    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && ele2 != nums[i])
        {
            cnt1 = 1;
            ele1 = nums[i];
        }
        else if (cnt2 == 0 && ele1 != nums[i])
        {
            cnt2 = 1;
            ele2 = nums[i];
        }
        else if (ele1 == nums[i])
            cnt1++;
        else if (ele2 == nums[i])
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }
    vector<int> out;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (ele1 == nums[i])
            cnt1++;
        if (ele2 == nums[i])
            cnt2++;
    }
    int miniVal = (int)(n / 3) + 1;
    if (cnt1 >= miniVal)
    {
        out.push_back(ele1);
    }
    if (cnt2 >= miniVal)
    {
        out.push_back(ele2);
    }
    return out;
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
    cout << "Output : ";
    printVector(bruteApproach(nums, n));
    cout << "Output : ";
    printVector(betterApproach(nums, n));
}