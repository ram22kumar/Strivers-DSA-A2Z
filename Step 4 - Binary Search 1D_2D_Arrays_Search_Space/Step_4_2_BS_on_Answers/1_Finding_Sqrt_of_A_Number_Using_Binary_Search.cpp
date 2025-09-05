#include <bits/stdc++.h>
using namespace std;
int optimalApproach(int n)
{
    int low = 0, high = n;
    int output = 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid * mid) > n)
        {
            high = mid - 1;
        }
        else
        {
            output = mid;
            low = mid + 1;
        }
    }
    return output;
}
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << optimalApproach(n);
}