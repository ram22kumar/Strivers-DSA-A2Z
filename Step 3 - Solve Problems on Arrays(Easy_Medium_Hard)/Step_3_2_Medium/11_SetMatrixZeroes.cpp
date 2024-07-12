#include <bits/stdc++.h>
using namespace std;
void printMatrix(vector<vector<int>> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}
void markRow(vector<vector<int>> &nums, int n, int m, int i)
{

    for (int j = 0; j < m; j++)
    {
        if (nums[i][j] != 0)
        {
            nums[i][j] = -1;
        }
    }
}
void markColumn(vector<vector<int>> &nums, int n, int m, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (nums[i][j] != 0)
        {
            nums[i][j] = -1;
        }
    }
}
vector<vector<int>> bruteApproach(vector<vector<int>> input, int n, int m)
{
    vector<vector<int>> nums = input;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            if (nums[i][j] == 0)
            {
                markRow(nums, n, m, i);
                markColumn(nums, n, m, j);
            }
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            if (nums[i][j] == -1)
            {
                nums[i][j] = 0;
            }
        }
    }
    return nums;
}
vector<vector<int>> betterApproach(vector<vector<int>> input, int n, int m)
{
    vector<vector<int>> nums = input;
    vector<int> rowVector(n, 0);
    vector<int> columnVector(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums[i][j] == 0)
            {
                rowVector[i] = 1;
                columnVector[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rowVector[i] == 1 || columnVector[j] == 1)
            {
                nums[i][j] = 0;
            }
        }
    }
    return nums;
}
vector<vector<int>> optimalApproach(vector<vector<int>> nums, int n, int m)
{
    //! Consider these and writing the code will be better.
    //* vector<int> rowVector(n,0) => nums[..][0];
    //* vector<int> columnVector(m,0) => nums[0][..];
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums[i][j] == 0)
            {
                nums[i][0] = 0;
                if (j != 0)
                {
                    nums[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (nums[i][j] != 0)
            {
                if (nums[0][j] == 0 || nums[i][0] == 0)
                {
                    nums[i][j] = 0;
                }
            }
        }
    }

    if (nums[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            nums[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            nums[i][0] = 0;
        }
    }
    return nums;
}
int main()
{
    int n, m;
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter m : ";
    cin >> m;
    vector<vector<int>> nums;
    for (int i = 0; i < n; i++)
    {
        vector<int> tempV;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            tempV.push_back(temp);
        }
        nums.push_back(tempV);
    }
    cout << "Brute Approach output : " << endl;
    printMatrix(bruteApproach(nums, n, m));
    cout << "Better Approach output : " << endl;
    printMatrix(betterApproach(nums, n, m));
    cout << "Optimal Approach output : " << endl;
    printMatrix(optimalApproach(nums, n, m));
}