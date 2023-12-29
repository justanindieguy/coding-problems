#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    int reversedNumber = 0, temp = x;
    while (temp)
    {
        int lastDigit = temp % 10;
        reversedNumber = reversedNumber * 10 + lastDigit;
        temp /= 10;
    }

    return reversedNumber == x;
}

int main()
{
    int x;
    cin >> x;

    cout << isPalindrome(x) << endl;

    return 0;
}
