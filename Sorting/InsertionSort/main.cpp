#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int currentIdx = i;
        while (currentIdx > 0 && v[currentIdx - 1] > v[currentIdx])
        {
            swap(v[currentIdx], v[currentIdx - 1]);
            currentIdx--;
        }
    }
}

int main()
{
    vector<int> v = {7, 3, 2, 5, 6, 10, 9, 8, 1};
    insertionSort(v);

    for (int num : v)
    {
        cout << num << ", ";
    }
    cout << endl;

    return 0;
}
