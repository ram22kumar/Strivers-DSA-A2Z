#include <bits/stdc++.h>
using namespace std;
vector<int> approach(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    vector<int> ans;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter m : ";
    cin >> m;
    cout << "Enter Matrix : ";
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        matrix.push_back(v);
    }
    vector<int> output = approach(matrix);
    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
}