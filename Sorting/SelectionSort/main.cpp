#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void selectionSort(vector<int> &v)
{
    int n = v.size();

    int minIndex;
    for (int i = 0; i < n; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[minIndex])
                minIndex = j;
        }

        swap(v[minIndex], v[i]);
    }
}

int main()
{
    vector<int> nums = {7, 3, 2, 5, 6, 10, 9, 8, 1};
    selectionSort(nums);

    for (int n : nums)
    {
        cout << n << ", ";
    }
    cout << endl;

    return 0;
}
