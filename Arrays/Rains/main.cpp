/*
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 */
#include <iostream>
#include <vector>

using namespace std;

int trappedWaterQuadratic(vector<int> heights)
{
    int n = heights.size();
    if (n < 3)
        return 0;

    int waterUnits = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        int j = i;
        int left = 0;
        while (j >= 0)
        {
            left = max(left, heights[j]);
            j--;
        }

        j = i;
        int right = 0;
        while (j < n)
        {
            right = max(right, heights[j]);
            j++;
        }

        waterUnits += min(left, right) - heights[i];
    }

    return waterUnits;
}

int trappedWaterLinear(vector<int> heights)
{
    int n = heights.size();
    if (n < 3)
        return 0;

    vector<int> lefts(n, 0), rights(n, 0);
    lefts[0] = heights[0];
    rights[n - 1] = heights[n - 1];
    for (int i = 1; i < n; i++)
    {
        lefts[i] = max(lefts[i - 1], heights[i]);
        rights[n - i - 1] = max(rights[n - i], heights[n - i - 1]);
    }

    int waterUnits = 0;
    for (int i = 0; i < n; i++)
    {
        waterUnits += min(lefts[i], rights[i]) - heights[i];
    }

    return waterUnits;
}

int main()
{
    vector<int> heights{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Water Units - Quadratic Time: " << trappedWaterQuadratic(heights) << endl;
    cout << "Water Units - Linear Time: " << trappedWaterLinear(heights) << endl;
    return 0;
}
