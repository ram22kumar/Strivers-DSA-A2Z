#include <bits/stdc++.h>
using namespace std;
void Pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void Pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void Pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void Pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void Pattern5(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
}
void Pattern6(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j
                 << " ";
        }
        cout << endl;
    }
}
void Pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void Pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 2 * (n - i - 1) + 1; k > 0; k--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void Pattern9(int n)
{
    Pattern7(n);
    Pattern8(n);
}
void Pattern10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void Pattern11(int n)
{
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << k << " ";
            k = !k;
        }
        cout << endl;
    }
}
void Pattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int k = 2 * (n - i); k > 0; k--)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}
void Pattern13(int n)
{
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << k++ << " ";
        }
        cout << endl;
    }
}
void Pattern14(int n)
{
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << char(ch + j) << " ";
        }
        cout << endl;
    }
}
void Pattern15(int n)
{
    char ch = 'A';
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << char(ch + j) << " ";
        }
        cout << endl;
    }
}
void Pattern16(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(i + 64) << " ";
        }
        cout << endl;
    }
}
void Pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i - 1; j >= 0; j--)
        {
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }
        cout << endl;
    }
}
void Pattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void Pattern19(int n)
{
    int inis = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < inis; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        inis += 2;
        cout << endl;
    }

    inis = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < inis; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        inis -= 2;
        cout << endl;
    }
}
void Pattern20(int n)
{
    int iniSpace = n - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int i = 0; i < iniSpace * 2; i++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        iniSpace -= 1;
        cout << endl;
    }
    iniSpace = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << "*";
        }
        for (int i = 0; i < iniSpace * 2; i++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << "*";
        }
        iniSpace += 1;
        cout << endl;
    }
}
void Pattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void Pattern22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << n - min(min(min(i, j), (2 * n - 1) - 1 - i), ((2 * n - 1) - 1 - j)) << " ";
        }
        cout << endl;
    }
}
int main()
{
    Pattern22(8);
    return 0;
}
