#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];

    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

int quickSelect(vector<int> &arr, int start, int end, int k)
{
    // Assuming that k will be inside the array - k < n.
    int p = partition(arr, start, end);
    if (p == k - 1)
        return arr[p];
    else if (k - 1 < p)
        return quickSelect(arr, start, p - 1, k);
    else
        return quickSelect(arr, p + 1, end, k);
}

int main()
{
    int k;
    cin >> k;

    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int n = arr.size();

    if (k > n)
        cout << "-1" << endl;
    else
        cout << quickSelect(arr, 0, n - 1, k) << endl;

    return 0;
}
