#include <iostream>
#include <vector>

using namespace std;

void sortTwoColors(vector<int> &colors)
{
    int n = colors.size(),
        low = 0, high = n - 1;

    while (low <= high)
    {
        switch (colors[low])
        {
        case 0:
            low++;
            break;
        case 1:
            swap(colors[low], colors[high]);
            high--;
            break;
        }
    }
}

void sortThreeColors(vector<int> &colors)
{
    int n = colors.size(),
        low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        switch (colors[mid])
        {
        case 0:
            swap(colors[low], colors[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(colors[high], colors[mid]);
            high--;
            break;
        }
    }
}

int main()
{
    vector<int> twoColors = {0, 1, 1, 0, 1, 0, 1, 1, 1, 1};
    sortTwoColors(twoColors);
    for (int color : twoColors)
    {
        cout << color << " ";
    }
    cout << endl;

    vector<int> threeColors = {2, 0, 2, 1, 1, 0};
    sortThreeColors(threeColors);
    for (int color : threeColors)
    {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}
