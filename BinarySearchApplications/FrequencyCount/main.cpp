/*
 * Given a sorted array which can contain repeated elements, and an element K,
 * we need to find the frequency of a given element.
 *
 * Input array:
 * [0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10]
 * Key = 2
 *
 * Output: 3
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// O(N)
int freqCountLinearSearch(vector<int> v, int k)
{
    int freq = 0;

    for (int n : v)
    {
        if (n == k)
            freq++;
    }

    return freq;
}

int getLowerBound(vector<int> v, int k)
{
    int n = v.size(),
        start = 0, end = n - 1;

    int lowerBound = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2,
            num = v[mid];

        if (num == k)
        {
            lowerBound = mid;
            end = mid - 1;
        }
        else if (num < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return lowerBound;
}

int getUpperBound(vector<int> v, int k)
{
    int n = v.size(),
        start = 0, end = n - 1;

    int upperBound = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2,
            num = v[mid];

        if (num == k)
        {
            upperBound = mid;
            start = mid + 1;
        }
        else if (num < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return upperBound;
}

int freqCountBinarySearch(vector<int> v, int k)
{
    int lowerBound = getLowerBound(v, k);

    if (lowerBound == -1)
        return 0;

    int upperBound = getUpperBound(v, k);

    return upperBound - lowerBound + 1;
}

int main()
{
    int k;
    cin >> k;

    vector<int> v = {0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};
    cout << "Frequency Count: " << freqCountBinarySearch(v, k) << endl;
    cout << "Frequency Count: " << upper_bound(v.begin(), v.end(), k) - lower_bound(v.begin(), v.end(), k) << endl;

    return 0;
}
