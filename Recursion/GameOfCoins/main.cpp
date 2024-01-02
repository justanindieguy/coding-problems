#include <iostream>
#include <vector>

using namespace std;

int gameOfCoins(vector<int> &v, int start, int end)
{
    if (start == end || start == end - 1)
    {
        return max(v[start], v[end]);
    }

    /*
     * Next turns:
     *   Player 2 chose start and Player 1 chose start
     *   Player 2 chose end and Player 1 start
     */
    int opt1 = v[start] + min(gameOfCoins(v, start + 2, end), gameOfCoins(v, start + 1, end - 1));

    /*
     * Next turns:
     *   Player 2 chose start and Player 1 chose end
     *   Player 2 chose end and Player 1 chose end
     */
    int opt2 = v[end] + min(gameOfCoins(v, start + 1, end - 1), gameOfCoins(v, start, end - 2));
    return max(opt1, opt2);
}

int maxValue(int n, vector<int> &v)
{
    return gameOfCoins(v, 0, n - 1);
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    cout << maxValue(v.size(), v) << endl;

    return 0;
}
