#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> v, int key)
{
    int n = v.size(),
        start = 0,
        end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2,
            num = v[mid];

        if (num == key)
            return mid;

        if (num < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int recursiveBinarySearch(vector<int> v, int key, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2,
        num = v[mid];

    if (num == key)
        return mid;

    if (num < key)
        return recursiveBinarySearch(v, key, mid + 1, end);
    else
        return recursiveBinarySearch(v, key, start, mid - 1);
}

int main()
{
    vector<int> v = {1, 2, 10, 11, 19, 28, 29};

    int k;
    cin >> k;

    cout << binarySearch(v, k) << endl;
    cout << recursiveBinarySearch(v, k, 0, v.size() - 1) << endl;

    return 0;
}
