/*
 * Given two binary strings a and b, return their sum as a binary string.
 *
 * Example 1:
 *
 *   Input:
 *     a = "11"
 *     b = "1"
 *
 *   Output: "100"
 *
 * Example 2:
 *
 *   Input:
 *     a = "1010"
 *     b = "1011"
 *
 *   Output: "10101"
 *
 * Constraints:
 *   1 <= a.length, b.length <= 104
 *   a and b consist only of '0' or '1' characters.
 *   Each string does not contain leading zeros except for the zero itself.
 *
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b)
{
    int carry = 0;
    string ans = "";

    while (!a.empty() || !b.empty() || carry > 0)
    {
        if (!a.empty())
        {
            carry += a.back() - '0';
            a.pop_back();
        }

        if (!b.empty())
        {
            carry += b.back() - '0';
            b.pop_back();
        }

        ans += to_string(carry % 2);
        carry /= 2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a = "1011", b = "1010";
    cout << a << " + " << b << " = " << addBinary(a, b) << endl;

    return 0;
}
