#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

// sort
// array,vector

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    // sort it so that only indexes from 1 to 3 are sorted
    //  take varr [1,6,2,7,4]
    sort(arr + 1, arr + 4); //[1,4)
    for (auto &&num : arr)
    {
        cout << num << ", ";
    }
    cout << "\n";
    reverse(arr, arr + n);
    for (auto &&num : arr)
    {
        cout << num << ", ";
    }
    cout << "\n";

    vector<int> vec(5, 0);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    // sort it so that only indexes from 1 to 3 are sorted
    //  take vec {1,6,2,7,4}
    sort(vec.begin(), vec.begin() + 4);

    // min and max elements in an array or vector

    int elMax = *max_element(arr, arr + n);
    int elMin = *min_element(arr, arr + n);
    // vector

    int elMaxVect = *max_element(vec.begin(), vec.end());
    int elMinVect = *min_element(vec.begin(), vec.end());

    // sum elements from i to j

    int sum = accumulate(arr, arr + 4, 0);

    // count the number of occurence of an element x
    // count(firstIterator, lastIterator , x);
    int cnt = count(arr, arr + n, 1);
    int cntV = count(vec.begin(), vec.end(), 1);

    // NOTE if you  subtruct the begin iterator from a current iterator you get the index

    // find the first occurrence of an element find() return an iterator

    auto fO = find(arr, arr + n, 3);
    int idx = fO - arr;

    auto fOV = find(vec.begin(), vec.end(), 4);
    if (fOV == vec.end())
    {
        cout << "Element not found";
    }
    else
    {
        int idxV = fOV - vec.begin();
    }

    // BinarySearch
    // binary_search(firstIterator,lastIterator,x) returns bool

    bool res = binary_search(vec.begin(), vec.end(), 3);

    // lowerbound returns an iterator to the first element that is >= x
    auto it = lower_bound(arr, arr + n, 4);

    // upperbound returns an iterator to the first element that is > x
    auto it = upper_bound(arr, arr + n, 4);

    // find the first occurence of an element x i logn time;
    int x = 2;
    int ind = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
    if (ind != vec.size() && vec[ind] == x)
    {
        cout << "Element found at ind: " << ind;
    }
    else
    {
        cout << "Element not Found";
    }
    // last occurence of an element in an array

    int lastOcc = upper_bound(arr, arr + n, x) - arr;
    lastOcc -= 1;
    if (lastOcc >= 0 && arr[lastOcc] == x)
    {
        cout << "Element is found at index: " << lastOcc - 1;
    }
    else
    {
        cout << "Element not found";
    }

    // next_permutation return true if the permutation was formed else false
    /**
     * lets tak the string s = "abc"
     * the possible permutations are "abc","acb","bac","bca","cab","cba"
     *
     *EG>>>>> lets take an example say you are told to print all the possible combinations of a string
     */
    // pair
    string s = "acb";
    sort(s.begin(), s.end());
    do
    {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
    // prev_permiutation
}
