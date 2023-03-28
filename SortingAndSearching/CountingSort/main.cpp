#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int> &v)
{
    int max = *max_element(v.begin(), v.end());
    vector<int> cntArr(max + 1, 0);
    vector<int> output(v.size(), 0);

    for (int val : v)
    {
        cntArr[val]++;
    }

    int n = cntArr.size();
    for (int i = 1; i < n; i++)
    {
        cntArr[i] += cntArr[i - 1];
    }

    int m = v.size();
    for (int i = 0; i < m; i++)
    {
        int num = v[i],
            correctPos = cntArr[num] - 1;

        cntArr[num]--;
        output[correctPos] = num;
    }

    for (int i = 0; i < m; i++)
    {
        v[i] = output[i];
    }
}

int main()
{
    vector<int> v = {4, 2, 2, 8, 3, 3, 1};
    countingSort(v);

    for (int val : v)
    {
        cout << val << ", ";
    }

    cout << endl;

    return 0;
}
