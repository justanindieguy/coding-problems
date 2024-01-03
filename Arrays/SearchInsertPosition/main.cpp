/*
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 *
 * You must write an algorithm with O(Log n) runtime complexity.
 *
 * Example 1:
 *
 *   Input: nums = [1, 3, 5, 6], target = 5
 *
 *   Output: 2
 *
 * Example 2:
 *
 *   Input: nums = [1, 3, 5, 6], target = 2
 *
 *   Output: 1
 *
 * Example 3:
 *
 *   Input: nums = [1, 3, 5, 6], target = 7
 *
 *   Output: 4
 */

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1, mid = 0;

    if (target > nums[end])
    {
        return end + 1;
    }
    else if (target < nums[start])
    {
        return start;
    }

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return start;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};

    int target;
    cin >> target;

    cout << binarySearch(nums, target) << endl;

    return 0;
}
