/*
 * Along one side of a road there is a sequence of vacant plots of land. Each
 * plot has a different area (non-zero). So, the areas form a sequence
 * A[1], A[2], ... A[N].
 *
 * You want to buy K acres of land to build a house. You want to find all
 * segments of contiguous plots (i.e., a subsection in the sequence) of whose
 * sum is exactly K.
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void getPrefixSumArrayRecursion(vector<int> v, vector<int> &ps, int i)
{
    if (i == v.size())
        return;
    if (i == 0)
        ps.push_back(v[0]);
    else
        ps.push_back(ps[i - 1] + v[i]);

    getPrefixSumArrayRecursion(v, ps, i + 1);
}

vector<int> getPrefixSumArray(vector<int> v)
{
    int sum = 0;
    vector<int> ps;

    for (int num : v)
    {
        sum += num;
        ps.push_back(sum);
    }

    return ps;
}

// O(N^2)
vector<pair<int, int>> housing(vector<int> v, vector<int> ps, int k)
{
    int n = v.size();
    vector<pair<int, int>> indices;

    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int area = (start == 0) ? ps[end] : (ps[end] - ps[start - 1]);

            if (area == k)
                indices.push_back({start, end});
        }
    }

    return indices;
}

// O(N LogN)
vector<pair<int, int>> housingBinarySearch(vector<int> ps, int k)
{
    vector<pair<int, int>> indices;

    for (int i = 0; i < ps.size(); i++)
    {
        int n = ps[i];
        if (n == k)
        {
            indices.push_back({0, i});
            continue;
        }

        auto itr = lower_bound(ps.begin(), ps.end(), n - k);
        int j = distance(ps.begin(), itr);
        if (n - ps[j] == k)
        {
            indices.push_back({j + 1, i});
        }
    }

    return indices;
}

// O(N) - Better!
vector<pair<int, int>> housingSlidingWindow(vector<int> v, int k)
{
    int n = v.size();
    int i = 0, j = 0, cs = 0;
    vector<pair<int, int>> indices;

    while (j < n)
    {
        // Expand to right
        cs += v[j];
        j++;

        // Remove elements from the left till cs > sum and i < j
        while (cs > k && i < j)
        {
            cs -= v[i];
            i++;
        }

        // Check if at any given point cs == k
        if (cs == k)
        {
            indices.push_back({i, j - 1});
        }
    }

    return indices;
}

// Smallest Window that contains the required sum
pair<int, int> housingSmallestWindow(vector<int> v, int k)
{
    int n = v.size();
    int i = 0, j = 0, cs = 0, sd = INT_MAX;
    pair<int, int> sw = {-1, -1};

    while (j < n)
    {
        cs += v[j];
        j++;

        while (cs > k && i < j)
        {
            cs -= v[i];
            i++;
        }

        int cd = j - i;
        if (cs == k && cd < sd)
        {
            sd = cd;
            sw = {i, j - 1};
        }
    }

    return sw;
}

vector<pair<int, int>> housingNegativeValues(vector<int> v, int k)
{
    int minVal = v[0];

    for (int num : v)
        minVal = min(num, minVal);

    minVal = abs(minVal);

    int n = v.size();
    for (int i = 0; i < n; i++)
        v[i] += minVal;

    int cs = v[0];
    int ts = k + minVal;
    int i = 0, j = 1;
    vector<pair<int, int>> indices;

    while (j < n)
    {
        cs += v[j];
        ts += minVal;
        j++;

        while (cs > ts && i < j)
        {
            cs -= v[i];
            ts -= minVal;
            i++;
        }

        if (cs == ts)
            indices.push_back({i, j - 1});
    }

    return indices;
}

int main()
{
    int k;
    cin >> k;

    // vector<int> v = {2, 1, 4, 1, 3, 2, 1, 1, 2, 1, 3};
    // vector<int> v = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
    // vector<int> ps = getPrefixSumArray(v);

    vector<int> v = {1, -2, 2, -1, 4, 1, 3, -1, -3, 2, 1, 1, 2};
    vector<pair<int, int>> indices = housingNegativeValues(v, k);

    for (auto &&pair : indices)
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;

    return 0;
}
