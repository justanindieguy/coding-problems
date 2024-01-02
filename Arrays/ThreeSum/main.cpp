#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> triplets{};

    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                triplets.push_back({nums[i], nums[j], nums[k]});

                while (j < k && nums[j] == nums[j + 1])
                {
                    j++;
                }

                while (j < k && nums[k] == nums[k - 1])
                {
                    k--;
                }

                j++;
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    return triplets;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = threeSum(nums);

    for (vector<int> &t : triplets)
    {
        for (int n : t)
        {
            cout << n << " ";
        }

        cout << endl;
    }

    return 0;
}
