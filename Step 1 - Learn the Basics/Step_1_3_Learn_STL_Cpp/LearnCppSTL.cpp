#include <bits/stdc++.h>
using namespace std;
void understandingPair()
{
    //* Pairs are a basic Data Structure in Cpp STL as they can start storing variables from 2 to n(By nesting)

    //? Single Pair
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    //? Nested Pair Example
    pair<int, pair<int, int>> nPair = {1, p};
    cout << nPair.first << " " << nPair.second.first << " " << nPair.second.second << endl;
}

void understandingVector()
{
    vector<int> v;
    v.push_back(8);    //? One way of Adding elements at last
    v.emplace_back(9); //? Another way to add elements at Last
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    //* Access Vector Elements is similar to arrays.
    cout << v[0] << endl;

    //* Another way to access is by using iterators
    vector<int>::iterator it = v.begin();           //? To get 0th Element
    it++;                                           //! This will move a step forward and points to 1st Element
    vector<int>::iterator it2 = v.end();            //? To get nth Element
    it2--;                                          //! This will move a step backward and points to n-1 th Element
    vector<int>::reverse_iterator it3 = v.rbegin(); //? These are not so important as they are just reversed version of begin()
    it3++;                                          //! This will move a step backward and points to n-1 th ELement as its reverse iterator which will point to n initally
    vector<int>::reverse_iterator it4 = v.rend();   //? These are not so important as they are just reversed version of end()
    it4--;                                          //! This will move a step backward and points to 1st ELement as its reverse iterator which will point to 0 initally

    //* Test the iterator with this
    cout << *(it) << " Printed element Using Iterator" << endl;
    //* Another way to access is by using .at method
    cout << v.at(2) << " Printed element using .at() method" << endl;
    //! Another way to access Last Element is by using .back() method;
    cout << v.back() << " Printed element using .back() method" << endl;

    //? Ways to print vector
    //* 1. Using Iterator
    cout << "Printing elements using iterator : ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    //* 2. A much simpler way is to use auto
    cout << "Printing elements using auto : ";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    //* 3. Using a for-each loop
    cout << "Printing elements using for-each loop : ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    //? Deletion in a vector by using .erase() method
    v.erase(v.begin() + 1); //* Deletes 9;
    cout << "Printing elements after erasing 9 : ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    v.erase(v.begin() + 1, v.begin() + 3);
    cout << "Printing elements after erasing 10,11 : ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    v.insert(v.begin() + 1, 11);
    v.insert(v.begin() + 1, 10);
    v.insert(v.begin() + 1, 9);
    cout << "Printing elements after inserting 9,10,11 : ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    //? Get size of vector by using .size();
    cout << "Printing size of vector v : ";
    cout << v.size() << endl;

    //? Remove last element by using .pop_back();
    v.pop_back();
    cout << "Printing vector after Removing Last element v : ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Swap helps to swap two vectors" << endl;
    cout << ".clear() helps in erases the vector" << endl;
    cout << ".empty() gives true if vector is empty else false" << endl;
}

void understandingLists()
{
    list<int> l;
    l.push_back(10);
    l.emplace_back(20);

    l.push_front(5); //* Is better compared to other insertions as list in STL is DLL.
    l.emplace_front(1);

    cout << "Printing elements after insertion : ";
    for (auto it : l)
    {
        cout << it << " ";
    }
    cout << endl;
}

void understandingStack()
{

    //? LIFO => Last In First Out

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);

    cout << st.top() << endl; // Prints 5
    //! Can't access elements through st[2] this method.

    st.pop();
    cout << st.top() << endl;   // 4
    cout << st.size() << endl;  // 4
    cout << st.empty() << endl; //! is empty

    stack<int> st1;
    st1.swap(st);
}

void understandingQueue()
{

    // ? FIFO => First In First Out

    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);

    q.back() += 5;
    cout << q.back() << " Printed last element using .back()\n";

    cout << q.front() << " Printed 1st element using .front()\n";

    q.pop();

    cout << q.back() << " Printed last element using .back() after deletion\n";
}

void understandingPriorityQueue()
{
    priority_queue<int> pq; //! To store Max-heap

    //? Push -> TC : O(logn)
    pq.push(7);    //{7}
    pq.push(10);   //{10,7}
    pq.push(5);    //{10,7,5}
    pq.emplace(2); //{10,7,5,2}

    //? Top -> TC : O(1)
    cout << pq.top() << " Printed Top of the Priority Queue which would be maximum element\n"; // Prints 10
    //? Pop -> TC : O(logn)
    pq.pop(); // Removes 10;

    cout << pq.top() << " After removal of the maximum element\n";

    priority_queue<int, vector<int>, greater<int>> mPq; //! To Store Min-Heap
    mPq.push(7);                                        //{7}
    mPq.push(10);                                       //{7,10}
    mPq.push(5);                                        //{5,7,10}
    mPq.emplace(2);                                     //{2,5,7,10}

    cout << mPq.top() << " Printed Top of the Priority Queue which would be minimum element\n"; // Prints 2
    mPq.pop();                                                                                  // Removes 2;
    cout << mPq.top() << "After removal of the minimum element\n";
}

void understandingSet()
{
    //? Stores in Sorted manner and
    //! doesn't allow duplicates
    set<int> s;

    // ? Push -> TC :
    s.insert(1);  //{1}
    s.emplace(2); //{1,2}
    s.insert(2);  // Insertion won't happen
    s.insert(4);  //{1,2,4}
    s.insert(3);  //{1,2,3,4}

    auto it = s.find(2);
    cout << *(it) << " Found the element" << endl;

    int count = s.count(3); //! If element available count = 1 else count will be 0;
    cout << count << " When Found" << endl;
    count = s.count(30); //! If element available count = 1 else count will be 0;
    cout << count << " When not found" << endl;
    //? .erase() is similar to what is available in vector

    //*The Following are common for set & vector
    /*
    ! C++ STL has Binary Search
    lets say A[] = {1,2,3,5,6}
    bool res = binary_search(A,A+n,4) -> //? WIll be False
    bool res = binary_search(A,A+n,3) -> //? WIll be True
    */

    //* lower_bound
    /*
    * A[] = {1,4,5,6,6,9};
    indexs-> 0,1,2,3,4,5,6
    ! lower_bound -> Helps in finding the element if it is found it will point to the element, if it's not found it will point to its immediate next value.
    ? int ind = lower_bound(A,A+n,4) - A; -> O/p : 1 - To get the index we do a substraction with A(.begin()-> Iterator)
    ? int inx = lower_bound(A,A+n,7) - A; -> O/p : 4
    ? int index = lower_bound(A,A+n,12) - A; -> O/p : 6
    */

    //* upper_bound
    /*
    * A[] = {1,4,5,6,7,9};
    index->  0,1,2,3,4,5,6
    ! upper_bound -> Helps in finding the element if it is found it will not point to the element but it will point to its immediate next element, if it's not found it will point to its immediate next value.
    ? int ind = upper_bound(A,A+n,7) - A; -> To get the index we do a substraction with A(.begin()-> Iterator)
    */
}

void understandingMultiSet()
{
    //* Similar to set will be in sorted order but allows duplicates
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    ms.erase(1); //! Erases all 1's
    ms.insert(1);
    ms.insert(1);

    int count = ms.count(1); //! Gives number of 1's -> 2 in this case

    //! To delete a single element pass the address of it.
    ms.erase(ms.find(1));
}

void understandingUnorderedSet()
{
    // * Stores duplicates but doesn't stores in sorted order.
    unordered_set<int> us;

    //! Most of the functions are O(1) but lower_bound & upper_bound are not allowed.
}

void understandingMap()
{

    //* Will store in Sorted Order
    map<int, int> mp;

    map<int, pair<int, int>> mppair;

    map<pair<int, int>, int> mpair;

    mp[1] = 2;
    mp.insert({3, 1});
    mp.emplace(2, 4);

    cout << mp[2] << endl;
    auto it = mp.find(2);

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mp[5] << " Prints 0 because value is not present for this key\n";
}

void understandingMultiMap()
{
    // * Everything same as map, only it can store multiple keys
    // ! Accessing elements via mp[key] cannot be used.
}

void understandingUnorderedMap()
{
    //* unordered_map is used to store elements as key, value pairs in non-sorted order.
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    if (p1.first > p2.first)
        return true;
    return false;
}

void algorithms()
{
    int a[] = {1, 5, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n); //? Sorting of array
    cout << "Sorted in increasing order : ";
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> v{1, 8, 16, 4};
    sort(v.begin(), v.end()); //? Sorting of Vector

    //? To sort a portion
    // sort(a + 2, a + 4);

    //! To sort them in descending order use greater<int> as comparator
    sort(a, a + n, greater<int>());
    cout << "Sorted in decreasing order : ";
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    //! To sort them in myWay we can use comparator function
    pair<int, int> pArry[] = {{1, 2}, {2, 1}, {4, 1}};
    int sizeP = sizeof(pArry) / sizeof(pair<int, int>);
    cout << sizeP << endl;

    //? Sort it according to second element
    //? if second element is same, then sort it according to first element in descending
    sort(pArry, pArry + sizeP, comp);
    for (auto p : pArry)
    {
        cout << p.first << " " << p.second << endl;
    }

    int num = 7;
    int count = __builtin_popcount(num); //! To Count the number of SET Bits for a given number use this __builtin_popcount(num) method.
    // TODO If the number is long long use __builtin_popcountll(num)
    cout << "Number of bits in " << num << " are : " << count << endl;

    //? Next Permutation
    string s = "1234";
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    cout << "All Permutations completed." << endl;

    //!! *max_element & *min_element are both used to get the maximum & minimum elements of an array or vector.
    int maximumEle = *max_element(a, a + n);
    cout << maximumEle << endl;
    int minimumEle = *min_element(a, a + n);
    cout << minimumEle << endl;
}
int main()
{
    algorithms();
}