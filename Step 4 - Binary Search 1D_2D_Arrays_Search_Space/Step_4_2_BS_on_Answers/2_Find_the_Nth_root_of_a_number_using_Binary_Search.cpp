#include <bits/stdc++.h>
using namespace std;
int func(int mid, int n, int m)
{
    long long output = 1;
    for (int i = 1; i <= n; i++)
    {
        output *= mid;
        if (output > m)
            return 2;
    }
    if (output == m)
        return 1;
    else
        return 0;
}
int optimalApproach(int n, int m)
{
    int low = 0, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, m;
    cout << "Enter n,m : ";
    cin >> n >> m;
    cout << optimalApproach(n, m);
}