/*
 * Given an array of intervals where intervals[i] = [start, end], merge all
 * overlapping intervals, and return an array of non-overlapping intervals that
 * cover all the intervals in the input
 *
 * Example 1:
 *
 *   Input: intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
 *   Output: [[1, 6], [8, 10], [15, 18]]
 *
 *   Explanation:
 *     Since intervals [1, 3] and [2, 6] overlap, merge them into [1, 6].
 *
 * Example 2:
 *
 *   Input: intervals = [[1, 4], [4, 5]]
 *   Output: [[1, 5]]
 *
 *   Explanation:
 *     Intervals [1, 4] and [4, 5] are considered overlapping.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printIntervals(vector<vector<int>> &intervals)
{
    for (vector<int> &i : intervals)
    {
        cout << "[" << i[0] << ", " << i[1] << "] ";
    }

    cout << endl;
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    if (n <= 1)
    {
        return intervals;
    }

    // Sort intervals by start
    sort(intervals.begin(), intervals.end(), [](auto &left, auto &right)
         { return left[0] < right[0]; });

    vector<vector<int>> ans = {};
    vector<int> prev = intervals[0];
    for (int i = 1; i < n; i++)
    {
        // Two intervals overlap if current's start is less than or equal to prev's end
        if (intervals[i][0] <= prev[1])
        {
            prev[1] = max(prev[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(prev);
            prev = intervals[i];
        }
    }

    ans.push_back(prev);
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {4, 6}, {5, 7}, {8, 10}, {9, 12}, {13, 14}};
    vector<vector<int>> merged = mergeIntervals(intervals);
    printIntervals(merged);

    return 0;
}
