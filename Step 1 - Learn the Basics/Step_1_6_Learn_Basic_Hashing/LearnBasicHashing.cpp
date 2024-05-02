#include <bits/stdc++.h>
using namespace std;
void countFrequency()
{

    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> nums;
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    unordered_map<int, int> uMap;
    for (int i = 0; i < n; i++)
    {
        uMap[nums[i]]++;
    }
    for (auto i : uMap)
    {
        cout << "nums value : " << i.first << " counts : " << i.second << endl;
    }
}
void highLowFrequencyElement()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> nums;
    cout << "Enter nums : ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    unordered_map<int, int> uMap;
    for (int i = 0; i < n; i++)
    {
        uMap[nums[i]]++;
    }

    int maxElement, minElement;
    int maxElementCount = INT_MIN, minElementCount = INT_MAX;
    for (auto i : uMap)
    {
        if (maxElementCount < i.second)
        {
            maxElementCount = i.second;
            maxElement = i.first;
        }
        if (minElementCount > i.second)
        {
            minElementCount = i.second;
            minElement = i.first;
        }
    }
    cout << "Max Element : " << maxElement << " is " << maxElementCount << "\nMin Element : " << minElement << " is " << minElementCount << endl;
}
int main()
{
    // countFrequency();
    highLowFrequencyElement();
}