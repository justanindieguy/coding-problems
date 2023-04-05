/*
 * Given a sorted array of strings that is interspersed with empty strings,
 * write a method to find the location of a given string.
 *
 * Input
 * ["ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""]
 * bat
 *
 * Output
 * 4
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sparseSearch(vector<string> v, string key)
{
    int n = v.size();

    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int midLeft = mid - 1;
        int midRight = mid + 1;

        if (v[mid] == "")
        {
            // Update mid to point to the nearest non-empty string.
            while (true)
            {
                if (midLeft < start && midRight > end)
                {
                    return -1;
                }
                else if (midLeft >= start && v[midLeft] != "")
                {
                    mid = midLeft;
                    break;
                }
                else if (midRight <= end && v[midRight] != "")
                {
                    mid = midRight;
                    break;
                }

                midLeft--;
                midRight++;
            }
        }

        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    vector<string> v{"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""};

    string key;
    cin >> key;

    cout << sparseSearch(v, key) << endl;

    return 0;
}
