/*
 * Write a function that takes in an array and returns two integers, denoting
 * starting and ending indices of the smallest sub-array in the input array
 * that needs to be sorted in place so that the entire input is sorted.
 *
 * If the input array is already sorted, return a pair [-1, -1].
 *
 * Sample Input:
 * [0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29]
 *
 * Sample Output:
 * [4, 6]
 *
 * Explanation:
 * If we sort sub-array [10, 11, 7] then entire array becomes sorted.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> subArraySorting(vector<int> v)
{
    vector<int> sorted(v.begin(), v.end());
    sort(sorted.begin(), sorted.end());

    int i = 0;
    int n = v.size();
    while (i < n && v[i] == sorted[i])
    {
        i++;
    }

    int j = n - 1;
    while (j >= 0 && v[j] == sorted[j])
    {
        j--;
    }

    if (i == n)
        return {-1, -1};

    return {i, j};
}

pair<int, int> subArraySortingLinear(vector<int> v)
{
    int n = v.size() - 1,
        end = -1,
        currMax = v[0];

    bool sorted = true;

    /*
     * Traverse from left to right and update the currMax.
     * If any element in the array comes out to be smallest than the currMax,
     * update the end index;
     */
    for (int i = 1; i <= n; i++)
    {
        if (v[i] < currMax)
        {
            end = i;
            sorted = false;
        }
        else
        {
            currMax = v[i];
        }
    }

    int start = -1,
        currMin = v[n];

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > currMin)
        {
            start = i;
        }
        else
        {
            currMin = v[i];
        }
    }

    if (sorted)
        return {-1, -1};

    return {start, end};
}

int main()
{
    vector<int> v = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};

    pair<int, int> indices = subArraySortingLinear(v);
    cout << "{" << indices.first << ", " << indices.second << "}" << endl;

    return 0;
}
