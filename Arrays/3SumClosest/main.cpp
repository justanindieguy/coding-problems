#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int closest(vector<int> &nums, int target)
{
    int n = nums.size();

    if (n == 3)
    {
        return nums[0] + nums[1] + nums[2];
    }

    sort(nums.begin(), nums.end());

    int closestSum = INT_MAX;

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (abs(target - sum) < abs(target - closestSum))
            {
                closestSum = sum;
            }

            if (sum > target)
            {
                k--;
            }
            else if (sum < target)
            {
                j++;
            }
            else
            {
                return sum;
            }
        }
    }

    return closestSum;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};

    int target;
    cin >> target;

    cout << closest(nums, target) << endl;

    return 0;
}
