/*
 * Given an array of size at-least two, find the smallest sub-array that needs to
 * be sorted in place so that entire input array becomes sorted.
 *
 * If the input array is already sorted, the function should return [-1, -1],
 * otherwise return the start & end index of smallest sub-array.
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> subArraySortSorting(vector<int> arr)
{
    // Brute (NLogN Time + O(LogN) space)
    int n = arr.size();
    vector<int> sortedArr(arr);
    sort(arr.begin(), arr.end());

    int i = 0;
    while (i < n && arr[i] == sortedArr[i])
        i++;

    int j = n - 1;
    while (j > -1 && arr[j] == sortedArr[j])
        j--;

    if (i == n)
        return {-1, -1};

    return {i, j};
}

bool outOfOrder(vector<int> arr, int i)
{
    int num = arr[i];

    if (i == 0)
        return num > arr[1];

    if (i == arr.size() - 1)
        return num < arr[i - 1];

    return num > arr[i + 1] || num < arr[i - 1];
}

pair<int, int> subArraySortLinear(vector<int> arr)
{
    int n = arr.size();
    int smallest = INT_MAX;
    int greatest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, num);
            greatest = max(greatest, num);
        }
    }

    if (smallest == INT_MAX)
        return {-1, -1};

    // Find the start and end index where smallest and greatest lie.
    int start = 0;
    while (smallest >= arr[start])
        start++;

    int end = n - 1;
    while (greatest <= arr[end])
        end--;

    return {start, end};
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 10, 8, 5, 12, 6, 13, 14, 15};
    pair<int, int> sortingIndexes = subArraySortSorting(arr);
    pair<int, int> linearIndexes = subArraySortLinear(arr);
    cout << "Sorting: " << sortingIndexes.first << ", " << sortingIndexes.second << endl;
    cout << "Linear: " << linearIndexes.first << ", " << linearIndexes.second << endl;

    return 0;
}
