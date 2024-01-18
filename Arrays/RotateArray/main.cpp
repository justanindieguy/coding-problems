/*
 * Given an integer array nums, rotate the array to the right by k steps, where
 * k is non-negative.
 *
 * Example 1:
 *   Input:
 *     nums = [1, 2, 3, 4, 5, 6, 7], k = 3
 *   Output:
 *     [5, 6, 7, 1, 2, 3, 4]
 *   Explanation:
 *     rotate 1 steps to the right: [7, 1, 2, 3, 4, 5, 6]
 *     rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5]
 *     rotate 3 steps to the right: [5, 6, 7, 1, 2, 3, 4]
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief rotates the array by k steps by swapping the last element until it
 * reaches the first position. This process is repeated k times.
 *
 *
 * Time Complexity - O(N^2) in the worst case
 * Space Complexity - O(1) everything is in-place
 *
 * @param nums array of integers
 * @param k steps to rotate
 */
void rotateQuadratic(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
    {
        return;
    }

    if (k == 0)
    {
        return;
    }

    k %= n;
    while (k > 0)
    {
        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[i], nums[i - 1]);
        }

        k--;
    }
}

/**
 * @brief rotates the array by k steps by creating a new array and then moving
 * the first elements until n - k to their new position in i + k, then it moves
 * the last elements to their new position in (i + k) % n - beginning of new
 * array.
 *
 * Space Complexity - O(N) since it is creating a copy
 * Time Complexity - O(N) traversing the array only once
 *
 * @param nums array of integers
 * @param k steps to rotate
 */
void rotateLinearSpaceAndTime(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
    {
        return;
    }

    if (k == 0)
    {
        return;
    }

    vector<int> nums2(n);

    int i = 0;
    for (i; i < n - k; i++)
    {
        nums2[i + k] = nums[i];
    }

    for (i; i < n; i++)
    {
        nums2[(i + k) % n] = nums[i];
    }

    copy(nums2.begin(), nums2.end(), nums.begin());
}

/**
 * @brief rotates the array by k steps by first reversing the whole array.
 * After the array is reversed, two partitions need two be reverse separately:
 *   0 ... 0 + k
 *   0 + k ... n - 1
 *
 * @param nums array of integers
 * @param k steps to rotate
 */
void rotateLinear(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
    {
        return;
    }

    if (k == 0)
    {
        return;
    }

    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    int k;
    cin >> k;

    // rotateQuadratic(nums, k);
    // rotateLinearSpaceAndTime(nums, k);

    rotateLinear(nums, k);
    for (int n : nums)
    {
        cout << n << ", ";
    }

    cout << endl;
    return 0;
}
