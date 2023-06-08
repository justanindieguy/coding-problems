#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(m * n)
int bruteForceApproach(vector<vector<int>> m)
{
    int count = 0;
    for (vector<int> v : m)
    {
        for (int num : v)
        {
            if (num < 0)
                count++;
        }
    }

    return count;
}

// Time Complexity: O(m * log n)
int binarySearchApproach(vector<vector<int>> m)
{
    int count = 0;
    for (vector<int> v : m)
    {
        int n = v.size(),
            firstNegativeIdx = upper_bound(v.begin(), v.end(), 0, greater<int>()) - v.begin();

        count += (n - firstNegativeIdx);
    }

    return count;
}

// Time Complexity: O (m + n)
int linearTraversalApproach(vector<vector<int>> m)
{
    int count = 0,
        n = m[0].size(),
        currRowNegativeIdx = n - 1;

    for (vector<int> v : m)
    {
        while (currRowNegativeIdx >= 0 && v[currRowNegativeIdx] < 0)
            currRowNegativeIdx--;

        count += (n - (currRowNegativeIdx + 1));
    }

    return count;
}

int main()
{
    vector<vector<int>> matrix = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3},
    };

    cout << bruteForceApproach(matrix) << endl;
    cout << binarySearchApproach(matrix) << endl;
    cout << linearTraversalApproach(matrix) << endl;

    return 0;
}
