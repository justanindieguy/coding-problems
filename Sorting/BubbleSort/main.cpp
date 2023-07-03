#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v)
{
    int n = v.size();

    bool hasSwapped = true;
    while (hasSwapped)
    {
        hasSwapped = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
                hasSwapped = true;
            }
        }
    }
}

void optimizedBubbleSort(vector<int> &v)
{
    int n = v.size();
    bool hasSwapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        hasSwapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                hasSwapped = true;
            }
        }

        if (hasSwapped == false)
            break;
    }
}

int main()
{
    vector<int> v = {7, 3, 2, 1, 5, 6, 10, 9, 8};
    optimizedBubbleSort(v);

    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
