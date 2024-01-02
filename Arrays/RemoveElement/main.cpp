/*
 * Given an integer array nums and an integer val, remove all occurrences of val
 * in nums-in-place. The order of the elements may be changed. Then return the
 * number of elements in nums which are not equal to val.
 *
 * Consider the number of elements in nums which are not equal to val be k, to
 * get accepted, you need to do the following things:
 *
 *  - Change the array nums such that the first k elements of nums contain the
 *    elements which are not equal to val. The remaining elements of nums are
 *    not important as well as the size of nums.
 *
 *  - Return k
 */

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    // vector<int> nums = {3, 2, 2, 3};

    int val;
    cin >> val;

    int k = removeElement(nums, val);

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}
