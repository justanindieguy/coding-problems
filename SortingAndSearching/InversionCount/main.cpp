#include <iostream>
#include <vector>

using namespace std;

// Brute Force Approach - O(N^2)
int countInversionsBruteForce(vector<int> v)
{
    int count = 0, n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
                count++;
        }
    }

    return count;
}

int count(vector<int> &arr, int start, int end)
{
    int mid = (start + end) / 2;
    int i = start, j = mid + 1;

    vector<int> temp;
    int count = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            count += mid - i + 1;
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;
    for (int idx = start; idx <= end; idx++)
    {
        arr[idx] = temp[k];
        k++;
    }

    return count;
}

// Recursive Approach - O(N log N)
int countInversions(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return 0;

    int mid = (start + end) / 2;
    int c1 = countInversions(arr, start, mid);
    int c2 = countInversions(arr, mid + 1, end);
    int crossCount = count(arr, start, end);

    return c1 + c2 + crossCount;
}

int main()
{
    vector<int> v{0, 5, 2, 3, 1};

    int start = 0, end = v.size() - 1;
    cout << countInversions(v, start, end) << endl;

    return 0;
}
