/*
 * Implement a function that takes as input a vector of integers, and prints the
 * maximum sub-array sum that can be formed. A sub-array is defined as
 * consecutive segment of the array. If the numbers are negative, then return 0.
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maximumSubArraySum(vector<int> arr)
{
    int maxSoFar = INT_MIN;
    int maxTillNow = 0;

    for (int num : arr)
    {
        maxTillNow += num;
        if (maxSoFar < maxTillNow)
            maxSoFar = maxTillNow;
        if (maxTillNow < 0)
            maxTillNow = 0;
    }

    if (maxSoFar < 0)
        maxSoFar = 0;

    return maxSoFar;
}

int main()
{
    vector<int> arr{-1, 2, 3, 4, -2, 6, -8, 3};
    cout << "Maximum sub-array sum: " << maximumSubArraySum(arr) << endl;
    return 0;
}
