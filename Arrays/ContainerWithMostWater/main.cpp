/*
 * You are given an integer array "height" of length n. There are n vertical
 * lines drawn such that the two endpoints of the ith line are (i, 0) and
 * (i, height[i]).
 *
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 *
 * Notice that you may not slant the container.
 *
 * Example 1:
 *   Input: height = {1, 8, 6, 2, 5, 4, 8, 3, 7}
 *   Output: 49
 *
 *   Explanation:
 *   The above vertical lines are represented by array
 *   {1, 8, 6, 2, 5, 4, 8, 3, 7}. In this case, the max are of water
 *   (blue section) the container can contain is 49.
 *
 * Example 2:
 *   Input: height = {1, 1}
 *   Output: 1
 */

#include <algorithm>
#include <limits.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Brute force approach O(n^2)
 *
 * @param heights array of integers representing line heights
 * @return int maximum area between two lines
 */
int maxAreaBruteForce(vector<int> heights)
{
    int n = heights.size();

    if (n <= 1)
    {
        return 0;
    }

    int maxWater = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int currWater = (j - i) * min(heights[i], heights[j]);
            maxWater = max(maxWater, currWater);
        }
    }

    return maxWater;
}

/**
 * @brief Linear approach using two pointers.
 * This approach moves to the center the pointer with the lower height, only
 * traversing the array once.
 *
 * @param heights array of integers representing line heights
 * @return int maximum area between two lines
 */
int maxAreaLinear(vector<int> heights)
{
    int n = heights.size();

    if (n <= 1)
    {
        return 0;
    }

    int maxWater = INT_MIN,
        i = 0,
        j = n - 1;
    while (i < j)
    {
        int ithHeight = heights[i],
            jthHeight = heights[j],
            currWater = (j - i) * min(ithHeight, jthHeight);

        maxWater = max(currWater, maxWater);

        ithHeight < jthHeight ? i++ : j--;
    }

    return maxWater;
}

int main()
{
    // vector<int> heights = {1, 1};
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // cout << maxAreaBruteForce(heights) << endl;
    cout << maxAreaLinear(heights) << endl;

    return 0;
}
