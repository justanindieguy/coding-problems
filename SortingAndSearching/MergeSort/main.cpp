#include <iostream>
#include <vector>

using namespace std;

// Helper method
void merge(vector<int> &arr, int start, int end)
{
    int mid = (start + end) / 2;
    int i = start, j = mid + 1;

    vector<int> temp;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left array.
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right array.
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back the elements from temp to original array.
    int k = 0;
    for (int idx = start; idx <= end; idx++)
    {
        arr[idx] = temp[k];
        k++;
    }
}

// Sorting method
void mergeSort(vector<int> &arr, int start, int end)
{
    // Base case
    if (start >= end)
        return;

    // Recursive case
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    return merge(arr, start, end);
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};

    int start = 0, end = arr.size() - 1;
    mergeSort(arr, start, end);

    for (int x : arr)
    {
        cout << x << ", ";
    }
    cout << endl;

    return 0;
}
