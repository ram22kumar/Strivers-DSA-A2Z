#include <bits/stdc++.h>
using namespace std;

void nNTimeswithoutLoop(int i, int n)
{
    if (i <= n)
    {
        cout << n << endl;
        nNTimeswithoutLoop(i + 1, n);
    }
    return;
}

void printNameNtimes(int i, int n, string name)
{
    if (i <= n)
    {
        cout << name << endl;
        printNameNtimes(i + 1, n, name);
    }
    return;
}

void oneToN(int i, int n)
{
    if (i <= n)
    {
        cout << i << endl;
        oneToN(i + 1, n);
    }
    return;
}

void nToOne(int i)
{
    if (i >= 1)
    {
        cout << i << endl;
        nToOne(i - 1);
    }
    return;
}

int sumOfNnumbers(int i)
{
    if (i == 0)
    {
        return 0;
    }
    return i + sumOfNnumbers(i - 1);
}

int factorialOfNnumbers(int i)
{
    if (i == 1)
    {
        return 1;
    }
    return i * factorialOfNnumbers(i - 1);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseArray(int arr[], int start, int end)
{
    if (start < end)
    {
        swap(arr[start], arr[end]);
        reverseArray(arr, start + 1, end - 1);
    }
}

int stringPalindrome(string s, int start, int end)
{
    if (start < end)
    {
        if (s[start] == s[end])
        {
            stringPalindrome(s, start + 1, end - 1);
        }
        else
        {
            return -1;
        }
    }
    return 0;
}
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int last = fibonacci(n - 1);
    int slast = fibonacci(n - 2);
    cout << last + slast << " ";
    return last + slast;
}
int main()
{
    // int arr[] = {5, 4, 3, 2, 1};
    // int n = sizeof(arr) / sizeof(int);
    // reverseArray(arr, 0, n - 1);
    // printArray(arr, n);
    // * String reversal
    // string s;
    // cin >> s;
    // cout << s << "\n";
    // if (stringPalindrome(s, 0, s.length() - 1) == -1)
    // {
    //     cout << "Not a Palindrome";
    //     return 0;
    // }
    // cout << "Palindrome";
    // * Fibonacci Number
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}