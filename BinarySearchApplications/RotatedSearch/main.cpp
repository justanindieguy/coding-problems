/*
 * Write a function that takes input a sorted array of distinct integers, which
 * is rotated about a pivot point and finds the index of any given element.
 *
 * Sample Input
 * [7, 9, 10, 1, 2, 3, 4, 5, 6]
 * element = 4
 *
 * Sample Output: 6
 */

#include <iostream>
#include <vector>

using namespace std;

int rotatedSearchWithPivot(vector<int> v, int k)
{
    int n = v.size();

    int unsortedElementIdx = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] < v[i])
            unsortedElementIdx = i + 1;
    }

    int start = 0, end = n - 1;
    if (k >= v[start] && k <= v[unsortedElementIdx - 1])
        end = unsortedElementIdx - 1;
    else
        start = unsortedElementIdx;

    // Common binary search algorithm
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (v[mid] == k)
            return mid;

        if (v[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

// Most efficient solution
int rotatedSearch(vector<int> v, int k)
{
    int n = v.size(),
        start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (v[mid] == k)
            return mid;

        // Mid lies on the left ascending line
        if (v[start] <= v[mid])
        {
            if (k >= v[start] && k <= v[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        // Mid lies on the right ascending line
        else
        {
            if (k >= v[mid] && k <= v[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int k;
    cin >> k;

    vector<int> v = {4, 5, 6, 7, 0, 1, 2, 3};

    cout << rotatedSearch(v, k) << endl;
    cout << rotatedSearchWithPivot(v, k) << endl;

    return 0;
}
