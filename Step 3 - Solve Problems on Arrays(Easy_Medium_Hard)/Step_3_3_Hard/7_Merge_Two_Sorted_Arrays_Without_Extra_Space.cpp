#include <bits/stdc++.h>
using namespace std;
void printVectors(vector<int> nums1, vector<int> nums2, int n, int m)
{
    cout << "1st Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << "\n"
         << "2nd Array : ";
    for (int i = 0; i < m; i++)
    {
        cout << nums2[i] << " ";
    }
    cout << endl;
}
void bruteApproach(vector<int> &brute1, vector<int> &brute2, int n, int m)
{
    vector<int> nums;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (brute1[i] < brute2[j])
        {
            nums.push_back(brute1[i]);
            i++;
        }
        else
        {
            nums.push_back(brute2[j]);
            j++;
        }
    }
    while (i < n)
    {
        nums.push_back(brute1[i]);
        i++;
    }
    while (j < m)
    {
        nums.push_back(brute2[j]);
        j++;
    }
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            brute1[i] = nums[i];
        }
        else
        {
            brute2[i - n] = nums[i];
        }
    }
}
void optimalApproach(vector<int> &optimal1, vector<int> &optimal2, int n, int m)
{
    int left = n - 1;
    int right = 0;
    while (left >= 0 && right < m)
    {
        if (optimal1[left] > optimal2[right])
        {
            swap(optimal1[left], optimal2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(optimal1.begin(), optimal1.end());
    sort(optimal2.begin(), optimal2.end());
}
void swapIfGreater(vector<int> &optimal1, vector<int> &optimal2, int i, int j)
{
    if (optimal1[i] > optimal2[j])
    {
        swap(optimal1[i], optimal2[j]);
    }
}
void optimalApproach2(vector<int> &optimal1, vector<int> &optimal2, int n, int m)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            if (left < n && right >= n)
            {
                swapIfGreater(optimal1, optimal2, left, right - n);
            }
            else if (left >= n)
            {
                swapIfGreater(optimal1, optimal2, left - n, right - n);
            }
            else
            {
                swapIfGreater(optimal1, optimal2, left, right);
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}
int main()
{
    int n;
    cout << "Enter size of first array : ";
    cin >> n;
    cout << "Enter size of second array : ";
    int m;
    cin >> m;
    vector<int> brute1, optimal1;
    vector<int> brute2, optimal2;
    cout << "Enter nums1 elements : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        brute1.push_back(temp);
        optimal1.push_back(temp);
    }
    cout << "Enter nums2 elements : ";
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        brute2.push_back(temp);
        optimal2.push_back(temp);
    }
    bruteApproach(brute1, brute2, n, m);
    cout << "Brute Outputs : \n";
    printVectors(brute1, brute2, n, m);
    optimalApproach(optimal1, optimal2, n, m);
    cout << "Optimal Outputs : \n";
    printVectors(optimal1, optimal2, n, m);
}