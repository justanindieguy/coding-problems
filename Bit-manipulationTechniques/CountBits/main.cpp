#include <iostream>

using namespace std;

int countBits(int n)
{
    int count = 0;

    while (n > 0)
    {
        int lastBit = n & 1;
        count += lastBit;
        n = n >> 1;
    }

    return count;
}

// Counting Sets Bits: Hack (faster method)
int countBitsHack(int n)
{
    int ans = 0;
    while (n > 0)
    {
        // Removes the last set bit from the current number
        n = n & (n - 1);
        ans++;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << countBits(n) << endl;
    cout << countBitsHack(n) << endl;

    return 0;
}
