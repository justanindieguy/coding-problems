#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> tokenize(string s)
{
    string token;
    stringstream ss(s);
    vector<string> tokens{};
    while (getline(ss, token, ','))
    {
        tokens.push_back(token);
    }

    return tokens;
}

bool compare(string num1, string num2)
{
    return num1 + num2 > num2 + num1;
}

string getBiggestLexicographicalNumber(string s)
{
    vector<string> numbers = tokenize(s);
    sort(numbers.begin(), numbers.end(), compare);

    string output;
    for (string num : numbers)
    {
        output += num;
    }

    return output;
}

int main()
{
    string input = "";
    getline(cin, input);
    cout << getBiggestLexicographicalNumber(input) << endl;

    return 0;
}
