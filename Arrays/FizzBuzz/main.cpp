#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fizzbuzz(int n);

int main()
{
    vector<string> result = fizzbuzz(15);
    for (string val : result)
        cout << val << ", ";
    cout << endl;

    return 0;
}

vector<string> fizzbuzz(int n)
{
    vector<string> result;

    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
            result.push_back("FizzBuzz");
        else if (i % 3 == 0)
            result.push_back("Fizz");
        else if (i % 5 == 0)
            result.push_back("Buzz");
        else
            result.push_back(to_string(i));
    }

    return result;
}
