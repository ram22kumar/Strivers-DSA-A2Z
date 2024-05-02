#include <bits/stdc++.h>
using namespace std;

int main()
{
    //* int, long, long long, float, double
    // int x;
    // cin>>x;
    // cout<<x;

    //* string and getline
    // string s;
    // getline(cin, s);
    // cout << s;

    //* char
    // char ch;
    // cin >> ch;
    // cout << ch;

    //* if-else Statements
    //? Write a program that takes an input of age and prints if you are adult or not.
    // int age;
    // cin >> age;
    // if (age >= 18)
    // {
    //     cout << "Adult";
    // }
    // else
    // {
    //     cout << "Not an Adult";
    // }

    //? Write a school grading system:
    //? Below 25 - F
    //? 25 to 44 - E
    //? 45 to 49 - D
    //? 50 to 59 - C
    //? 60 to 79 - B
    //? 80 to 100 - A
    //? Ask user to enter marks and print the corresponding Grade.
    int marks;
    cout << "Enter Marks : ";
    cin >> marks;
    if (marks < 25)
    {
        cout << "F";
    }
    else if (marks <= 44)
    {
        cout << "E";
    }
    else if (marks <= 49)
    {
        cout << "D";
    }
    else if (marks <= 59)
    {
        cout << "C";
    }
    else if (marks <= 79)
    {
        cout << "B";
    }
    else if (marks <= 100)
    {
        cout << "A";
    }
    //* Switch Statement

    return 0;
}