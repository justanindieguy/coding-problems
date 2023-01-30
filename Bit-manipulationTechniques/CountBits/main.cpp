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

int main()
{
    int n;
    cin >> n;

    cout << countBits(n) << endl;

    return 0;
}
