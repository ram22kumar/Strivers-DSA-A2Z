#include <bits/stdc++.h>
using namespace std;
void printVector(vector<long long> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
void pascalTriangleRowAndCol(int n, int r)
{
    // n!/(r!)*(n-r)!
    long long ans = 1;
    for (int i = 0; i < r; i++)
    {
        ans = ans * (n - i);
        ans /= (i + 1);
    }
    cout << "Output : " << ans << endl;
}
void pascalTriangleRow(int n)
{
    vector<long long> ans;
    long long val = 1;
    ans.push_back(val);
    for (int i = 1; i < n; i++)
    {
        val = val * (n - i);
        val /= i;
        ans.push_back(val);
    }
    printVector(ans);
}
void pascalTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        pascalTriangleRow(i);
    }
}
int main()
{
    int choice, n, m;
    do
    {
        cout << "Enter 0 for Finding a value in the Pascal Triangle based on row and column value." << endl;
        cout << "Enter 1 for Finding the whole row in the Pascal Triangle of a particular row. " << endl;
        cout << "Enter 2 to Display the whole Pascal Triangle until N rows." << endl;
        cout << "Enter 4 to exit." << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Enter row value and column value : ";
            cin >> n >> m;
            pascalTriangleRowAndCol(n, m);
            break;
        case 1:
            cout << "Enter row value : ";
            cin >> n;
            pascalTriangleRow(n);
            break;
        case 2:
            cout << "Enter n : ";
            cin >> n;
            pascalTriangle(n);
            break;
        default:
            break;
        }
    } while (choice != 4);
}