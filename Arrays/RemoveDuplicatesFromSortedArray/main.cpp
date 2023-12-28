#include <iostream>
#include <vector>
#include <set>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int j = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}

int main()
{
    vector<int> v = {1, 1, 2, 2, 2, 3, 4, 4};

    int k = removeDuplicates(v);
    for (int i = 0; i < k; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
