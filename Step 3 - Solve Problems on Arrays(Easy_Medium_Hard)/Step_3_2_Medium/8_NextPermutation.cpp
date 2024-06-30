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

// * Brute Force follows the below method:
// * 1. Generate all the permutations.
// * 2. Sort the permutations.
// * 3. Linear search to find the permutations.
// * 4. Return the next permutation if exists else return the 1st permutation (If the input is the last permutation).

void recurPermute(int index, vector<int> &nums, vector<vector<int>> &all_permutations)
{
    if (index == nums.size())
    {
        all_permutations.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, all_permutations);
        swap(nums[index], nums[i]);
    }
}
vector<int> bruteApproach(vector<int> nums)
{
    vector<int> copy(nums.begin(), nums.end());
    int ans = 0;
    vector<vector<int>> all_permutations;
    recurPermute(0, copy, all_permutations);
    sort(all_permutations.begin(), all_permutations.end());
    for (int i = 0; i < all_permutations.size(); i++)
    {
        int counter = 0;
        for (int j = 0; j < all_permutations[i].size(); j++)
        {
            if (nums[j] == all_permutations[i][j])
            {
                counter++;
            }
        }
        if (counter == nums.size())
        {
            if (i == all_permutations.size() - 1)
            {
                ans = 0;
            }
            else
            {
                ans = i + 1;
            }
        }
    }
    for (int i = 0; i < copy.size(); i++)
    {
        copy[i] = all_permutations[ans][i];
    }
    return copy;
}

vector<int> betterApproach(vector<int> nums)
{
    vector<int> output(nums.begin(), nums.end());
    next_permutation(output.begin(), output.end());
    return output;
}

vector<int> optimalApproach(vector<int> nums)
{
    int n = nums.size();
    int breakPoint = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            breakPoint = i;
            break;
        }
    }
    if (breakPoint == -1)
    {
        reverse(nums.begin(), nums.end());
        return nums;
    }

    for (int i = n - 1; i > breakPoint; i--)
    {
        if (nums[i] > nums[breakPoint])
        {
            swap(nums[i], nums[breakPoint]);
            break;
        }
    }

    reverse(nums.begin() + breakPoint + 1, nums.end());
    return nums;
}

int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    cout << "Enter nums : ";
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    vector<int> bruteOutput = bruteApproach(nums);
    cout << "Brute Output : ";
    printVector(bruteOutput);
    vector<int> betterOutput = betterApproach(nums);
    cout << "Better Output : ";
    printVector(betterOutput);
    vector<int> optimalOutput = optimalApproach(nums);
    cout << "Optimal Output : ";
    printVector(optimalOutput);
}