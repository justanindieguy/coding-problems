/*
 * Implement a function that takes in two non-empty array of integers, find the
 * pair of numbers (one from each array) who absolute difference is closest to
 * zero, and returns a pair containing these two numbers, with the first number
 * from array. Only one such pair will exist for the test.
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> minDiffBruteForce(vector<int> arr1, vector<int> arr2)
{
    int minDiff = INT_MAX;
    pair<int, int> minimumPair;

    for (int num1 : arr1)
    {
        for (int num2 : arr2)
        {
            int diff = abs(num1 - num2);
            if (diff < minDiff)
            {
                minDiff = diff;
                minimumPair = {num1, num2};
            }
        }
    }

    return minimumPair;
}

pair<int, int> minDiff(vector<int> arr1, vector<int> arr2)
{
    int minDiff = INT_MAX;
    pair<int, int> minimumPair;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        int diff = abs(arr1[i] - arr2[j]);
        if (diff < minDiff)
        {
            minDiff = diff;
            minimumPair = {arr1[i], arr2[j]};
        }

        if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }

    return minimumPair;
}

int main()
{
    vector<int> arr1{23, 5, 10, 17, 30};
    vector<int> arr2{26, 134, 135, 14, 19};

    pair<int, int> minPair = minDiffBruteForce(arr1, arr2);
    pair<int, int> minPairTwo = minDiff(arr1, arr2);

    cout << minPair.first << ", " << minPair.second << endl;
    cout << minPairTwo.first << ", " << minPairTwo.second << endl;

    return 0;
}
