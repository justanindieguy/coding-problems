#include <iostream>
#include <climits>

using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
    {
        return 1;
    }

    bool isPositive = dividend > 0 == divisor > 0; // true both dividend and divisor have the same sign
    unsigned int divd = abs(dividend);             // short for dividend since this name is already used
    unsigned int divs = abs(divisor);              // short for divisor since this name is already used
    unsigned int ans = 0;

    // dividend = quotient * divisor + remain
    while (divd >= divs)
    {
        int exp = 0;

        /*
         * "<<" left-shift bitwise operator. a << b moves the bits in "a" by "b"
         * positions. Given as a result: a * 2^b
         *
         * This loop will increment the exp until the result of:
         *   divisor * 2^exp
         * is greater than the dividend.
         */
        while ((divs << (exp + 1)) < divd)
        {
            exp++;
        }

        /*
         * This will end up in adding all the powers of 2 that compose the quotient
         * i.e. getting the value of quotient by a binary representation.
         */
        ans += (1 << exp); // ans += 2^exp
        divd = divd - (divs << exp);
    }

    if (ans == (1 << 31) && isPositive)
    {
        return INT_MAX;
    }

    return isPositive ? ans : -ans;
}

int main()
{
    int dividend;
    cin >> dividend;

    int divisor;
    cin >> divisor;

    cout << "Result: " << divide(dividend, divisor) << endl;

    return 0;
}
