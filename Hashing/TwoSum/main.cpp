/*
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

pair<int, int> bruteForceApproach(vector<int> nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }

    return {-1, -1};
}

pair<int, int> linearApproach(vector<int> nums, int target)
{
    unordered_map<int, int> traversed = {};

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];

        if (traversed.count(complement) > 0)
        {
            return {i, traversed[complement]};
        }

        traversed[nums[i]] = i;
    }

    return {-1, -1};
}

int main()
{
    int target = 9;
    vector<int> nums = {2, 7, 11, 15};

    pair<int, int> ans = linearApproach(nums, target);
    cout << ans.first << ", " << ans.second << endl;

    return 0;
}
