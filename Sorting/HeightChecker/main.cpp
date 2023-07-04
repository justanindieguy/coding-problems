#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int heightChecker(vector<int> &heights)
{
    vector<int> sorted(heights);
    sort(sorted.begin(), sorted.end());

    int n = heights.size(),
        ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (heights[i] != sorted[i])
            ans++;
    }

    return ans;
}

int main()
{
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    cout << heightChecker(heights) << endl;

    return 0;
}
