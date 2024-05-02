#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> out)
{
    for (auto it : out)
    {
        cout << it << " ";
    }
    cout << endl;
}
vector<int> bruteForceApproach(int nums1[], int nums2[], int n, int m)
{
    vector<int> out;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        st.insert(nums2[i]);
    }
    for (auto it : st)
    {
        out.push_back(it);
    }
    return out;
}
vector<int> optimalApproach(int nums1[], int nums2[], int n, int m)
{
    vector<int> out;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (nums1[i] <= nums2[j])
        {
            if (out.size() == 0 || out.back() != nums1[i])
            {
                out.push_back(nums1[i]);
            }
            i++;
        }
        else
        {
            if (out.size() == 0 || out.back() != nums2[j])
            {
                out.push_back(nums2[j]);
            }
            j++;
        }
    }

    while (j < m)
    {
        if (out.size() == 0 || out.back() != nums2[j])
        {
            out.push_back(nums2[j]);
        }
        j++;
    }
    while (i < n)
    {
        if (out.size() == 0 || out.back() != nums1[i])
        {
            out.push_back(nums1[i]);
        }
        i++;
    }
    return out;
}
int main()
{
    cout << "Enter array sizes n & m : ";
    int n, m;
    cin >> n >> m;
    cout << "Enter array 1 elements of size n : ";
    int nums1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    cout << "Enter array 2 elements of size m : ";
    int nums2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }
    vector<int> bruteOutput = bruteForceApproach(nums1, nums2, n, m);
    printVector(bruteOutput);
    vector<int> optimalOutput = optimalApproach(nums1, nums2, n, m);
    printVector(optimalOutput);
}