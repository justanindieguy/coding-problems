#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<char> subset)
{
    for (auto item : subset)
    {
        if ((int)item != 0)
            cout << item << ", ";
        else
            cout << "";
    }

    cout << endl;
}

void generateSubsets(vector<char> arr, vector<char> subset, int i)
{
    if (i == arr.size())
    {
        printSubset(subset);
    }
    else
    {
        subset[i] = 0;
        generateSubsets(arr, subset, i + 1);
        subset[i] = arr[i];
        generateSubsets(arr, subset, i + 1);
    }
}

void powerSet(vector<char> arr)
{
    vector<char> subset(arr.size());
    generateSubsets(arr, subset, 0);
}

int main()
{
    vector<char> arr = {'a', 'b', 'c'};
    powerSet(arr);
    return 0;
}
