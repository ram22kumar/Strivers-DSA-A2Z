#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> output)
{
    for (auto it : output)
    {
        cout << (it) << " ";
    }
    cout << endl;
}
vector<int> bruteForceApproach(int nums1[], int nums2[], int n, int m)
{
    // TC:O(n*m);
    // SC:O(size(nums2))
    vector<int> output;
    int visited[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nums1[i] == nums2[j] && visited[j] == 0)
            {
                output.push_back(nums1[i]);
                visited[j] = 1;
                break;
            }
            if (nums2[j] > nums1[i])
                break;
        }
    }
    return output;
}
vector<int> optimalApproach(int nums1[], int nums2[], int n, int m)
{
    vector<int> output;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (nums1[i] == nums2[j])
        {
            output.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
    }
    return output;
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
    cout << "Brute Force Output array : ";
    printVector(bruteOutput);
    vector<int> optimalOutput = optimalApproach(nums1, nums2, n, m);
    cout << "Optimal Output array : ";
    printVector(optimalOutput);
}