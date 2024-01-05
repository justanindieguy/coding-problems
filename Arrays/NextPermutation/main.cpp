/*
 * A permutation of an array of integers is an arrangement of its members into a
 * sequence or linear order.
 *
 * For example, for arr = [1, 2, 3], the following are all the permutations of
 * arr: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
 *
 * The next permutation of an array of integers is the next lexicographically
 * greater permutation of its integer. More formally, if all the permutations of
 * the array are sorted in one container according to the lexicographical order,
 * then the next permutation of that array is the permutation that follows it in
 * the sorted container. If such arrangement is not possible, the array must be
 * rearranged as the lowest possible order (i.e., sorted in ascending order).
 *
 * For example, the next permutation of arr = [1, 2, 3] is [1, 3, 2].
 *
 * Similarly, the next permutation of arr = [2, 3, 1] is [3, 1, 2].
 *
 * While the next permutation of arr = [3, 2, 1] is [1, 2, 3] because [3, 2, 1]
 * does not have a lexicographical larger rearrangement.
 *
 * Given an array of integers, find the next permutation of nums.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();

    if (n <= 1)
    {
        return;
    }

    /*
     * Index of first element when ascending order -from right to left- starts
     * decreasing.
     */
    int fallingElIdx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            fallingElIdx = i;
            break;
        }
    }

    /*
     * If not falling idx is found, then the whole array is in decreasing order
     * (example: [3, 2, 1]) so it is the last permutations and to get the first
     * one the whole array must be reversed.
     */
    if (fallingElIdx == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    /*
     * Otherwise, find the first greater element than the element in the falling
     * idx, then swap them and reverse the rest of the array.
     * i. e.: fallingElementIdx + 1 until n
     */
    int nextGreaterElIdx = 0;
    for (int i = n - 1; i > fallingElIdx; i--)
    {
        if (nums[i] > nums[fallingElIdx])
        {
            nextGreaterElIdx = i;
            break;
        }
    }

    swap(nums[fallingElIdx], nums[nextGreaterElIdx]);
    reverse(nums.begin() + fallingElIdx + 1, nums.end());
}

int main()
{
    vector<int> nums = {2, 3, 5, 4, 1};

    cout << "Next permutation:" << endl;
    nextPermutation(nums);

    for (int n : nums)
    {
        cout << n << ", ";
    }

    cout << endl;
}
