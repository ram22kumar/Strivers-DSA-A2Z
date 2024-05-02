#include <bits/stdc++.h>
using namespace std;
int stockBuyAndSell(int nums[], int n)
{
    int mini = nums[0];
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int cost = nums[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, nums[i]);
    }
    return maxProfit;
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
    int maxProfit = stockBuyAndSell(nums, n);
    cout << "Max Profit is : " << maxProfit << endl;
}