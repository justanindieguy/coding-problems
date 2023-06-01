/*
 * Given two non-empty arrays, find the pair of numbers (one from each array)
 * whose absolute difference is minimum. Print that one with the smallest
 * difference.
 *
 * Sample Input
 * a1 = [-1, 5, 10, 20, 31]
 * a2 = [26, 134, 135, 15, 17]
 *
 * Sample Output
 * [20, 17]
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> bruteForceApproach(vector<int> v1, vector<int> v2)
{
    int minDiff = INT_MAX;
    pair<int, int> ans = {-1, -1};

    for (int num1 : v1)
    {
        for (int num2 : v2)
        {
            int diff = abs(num1 - num2);
            if (diff < minDiff)
            {
                minDiff = diff;
                ans = {num1, num2};
            }
        }
    }

    return ans;
}

int getLowerBound(vector<int> v, int x)
{
    int n = v.size(),
        start = 0, end = n - 1;

    int lowerBond = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2,
            num = v[mid];

        if (num < x)
        {
            start = mid + 1;
        }
        else
        {
            lowerBond = mid;
            end = mid - 1;
        }
    }

    if (lowerBond == -1)
        lowerBond = n;

    return lowerBond;
}

pair<int, int> binarySearchApproach(vector<int> v1, vector<int> v2)
{
    sort(v2.begin(), v2.end());

    int minDiff = INT_MAX;
    pair<int, int> ans = {-1, -1};

    // Iterate over the first array and look for closest element in the second array
    for (int x : v1)
    {
        auto lb = lower_bound(v2.begin(), v2.end(), x) - v2.begin();

        // Check immediate smaller element (left)
        if (lb > 0 && x - v2[lb - 1] < minDiff)
        {
            minDiff = x - v2[lb - 1];
            ans = {x, v2[lb - 1]};
        }

        // Check immediate greater element (right)
        if (lb != v2.size() && v2[lb] - x < minDiff)
        {
            minDiff = v2[lb] - x;
            ans = {x, v2[lb]};
        }
    }

    return ans;
}

int main()
{
    vector<int> v1 = {-1, 5, 10, 20, 3};
    vector<int> v2 = {26, 134, 135, 15, 17};

    pair<int, int> bruteForceAns = bruteForceApproach(v1, v2);
    cout << bruteForceAns.first << ", " << bruteForceAns.second << endl;

    pair<int, int> binarySearchAns = binarySearchApproach(v1, v2);
    cout << binarySearchAns.first << ", " << binarySearchAns.second << endl;

    return 0;
}
