/*
 *  Given an array containing N integers, find length of the longest band.
 *
 * A band is defined as a subsequence which can be reordered in such a manner
 * all elements appear consecutive (i.e. with absolute difference of 1 between
 * neighboring elements).
 *
 * A longest band is the band (subsequence) which contains maximum integers.
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestBandSorting(vector<int> arr)
{
    int n = arr.size();
    int maxLength = 0;
    int bandLength = 1;

    if (n == 1)
        return bandLength;

    sort(arr.begin(), arr.end());
    for (int i = 0; i <= n - 2; i++)
    {
        if (arr[i] + 1 == arr[i + 1])
        {
            bandLength++;
        }
        else
        {
            maxLength = max(maxLength, bandLength);
            bandLength = 1;
        }
    }

    return maxLength;
}

int longestBandMySolution(vector<int> arr)
{
    int maxLength = 0;
    unordered_set<int> present(arr.begin(), arr.end());
    unordered_set<int> checked = {};

    for (int i = 0; i < arr.size(); i++)
    {
        int curr = arr[i];
        if (checked.find(curr) != checked.end())
            continue;

        checked.insert(curr);
        int bandLength = 1;
        int prev = curr - 1;
        int next = curr + 1;

        while (present.find(prev) != present.end())
        {
            bandLength++;
            prev--;
            checked.insert(prev);
        }

        while (present.find(next) != present.end())
        {
            bandLength++;
            next++;
            checked.insert(next);
        }

        maxLength = max(maxLength, bandLength);
    }

    return maxLength;
}

// * Best solution
int longestBandSets(vector<int> arr)
{
    int maxLength = 0;
    unordered_set<int> present(arr.begin(), arr.end());

    for (int curr : arr)
    {
        // Check whether current element is head of a band or not...
        // If it is NOT A HEAD, then ignore it
        int prev = curr - 1;
        if (present.find(prev) != present.end())
            continue;

        // If it is a HEAD, get the band length
        int bandLength = 1;
        int next = curr + 1;
        while (present.find(next) != present.end())
        {
            bandLength++;
            next++;
        }

        maxLength = max(maxLength, bandLength);
    }

    return maxLength;
}

int main()
{
    // * Longest Band = 0, 1, 2, 3, 4, 5, 6, 7 - Length = 8
    vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout << "Sorting: " << longestBandSorting(arr) << endl;
    cout << "Sets: " << longestBandSets(arr) << endl;
    cout << "Sets (my solution): " << longestBandMySolution(arr) << endl;
    return 0;
}
