#include <bits/stdc++.h>
using namespace std;

void countDigits1(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n /= 10;
    }
    cout << count << endl;
}

void countDigits2(int n)
{
    int count = (int)(log10(n) + 1);
    cout << "Number of digits using log10 : " << count << endl;
}

void reverseDigits1(int n)
{
    int reverseN = 0;
    while (n > 0)
    {
        reverseN = reverseN * 10 + n % 10;
        n /= 10;
    }
    cout << "Reverse of " << n << " is : " << reverseN << endl;
}

void isPalindrome(int num)
{
    int n = num;
    int reverseN = 0;
    while (n > 0)
    {
        reverseN = reverseN * 10 + n % 10;
        n /= 10;
    }
    if (num == reverseN)
    {
        cout << "It is Palindrome." << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }
}

void armstrongNumber(int n)
{
    int len = (int)(log10(n) + 1);
    int armstgNum = 0;
    while (n > 0)
    {
        armstgNum += pow(n % 10, len);
        n /= 10;
    }
    cout << armstgNum << endl;
}

void printAllDivisors(int n)
{
    set<int> st;
    int i = 1;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            st.insert(i);
            if ((n / i) != i)
                st.insert(n / i);
        }
        i++;
    }
    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << endl;
}

void isPrime(int n)
{
    // * Prime Number : A Number which exactly has two factors 1 & itself.

    int count1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count1++;
        }
    }
    if (count1 == 2)
    {
        cout << n << " is Prime" << endl;
    }
    else
    {
        cout << n << " is not a Prime" << endl;
    }

    //* Limit the loop limit to sqrt(n)
    int count2 = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count2++;
            if ((n / i) != i)
            {
                count2++;
            }
        }
    }
    if (count2 == 2)
    {
        cout << n << " is Prime" << endl;
    }
    else
    {
        cout << n << " is not a Prime" << endl;
    }
}

void gcd_HCF(int n1, int n2)
{
    //* GCD (Greatest Common Divisor) / HCF (Highest Common Factor) :

    int gcd1 = 0;
    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd1 = i;
        }
    }
    cout << "GCD of " << n1 << " & " << n2 << " is : " << gcd1 << endl;

    //! Compared to the above solution the below one is better as it is coming from last.

    int gcd2 = 0;
    for (int i = min(n1, n2); i >= 1; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd2 = i;
            break;
        }
    }
    cout << "GCD of " << n1 << " & " << n2 << " is : " << gcd2 << endl;

    //! GCD(a,b) = GCD(a - b, b) where a > b
    //! GCD(a,b) = GCD(a % b, b) where a > b

    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 = n1 % n2;
        else
            n2 = n2 % n1;
    }
    if (n1 == 0)
        cout << "GCD is : " << n2 << endl;
    else
        cout << "GCD is : " << n1 << endl;
}

int main()
{
    gcd_HCF(7, 1007);
}