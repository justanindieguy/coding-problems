/*
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping you
 * from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent houses
 * were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight with alerting the
 * police
 */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();

    int prevFirst = 0, prevSecond = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = prevFirst;
        prevFirst = max(prevSecond + nums[i], prevFirst);
        prevSecond = temp;
    }

    return prevFirst;
}

int main()
{
    vector<int> nums = {2, 1, 1, 2};
    cout << rob(nums) << endl;

    return 0;
}
