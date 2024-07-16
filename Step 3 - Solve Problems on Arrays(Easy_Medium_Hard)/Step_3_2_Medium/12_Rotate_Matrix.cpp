#include <bits/stdc++.h>
using namespace std;
void printMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> bruteApproach(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<vector<int>> nums = matrix;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << "i j" << j << " " << (n - i - 1) << endl;
            nums[j][n - i - 1] = matrix[i][j];
        }
    }
    return nums;
}
void optimalApproach(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    cout << "Enter matrix : " << endl;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        matrix.push_back(v);
    }
    vector<vector<int>> bruteOutput = bruteApproach(matrix);
    cout << "Brute force output : " << endl;
    printMatrix(bruteOutput);
    optimalApproach(matrix);
    cout << "Optimal Approach in-place : " << endl;
    printMatrix(matrix);
}