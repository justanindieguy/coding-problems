#include <iostream>
#include <string>

using namespace std;

string compressString(string s)
{
    if (s.size() == 0)
        return "";

    int total = 1;
    char curr = s[0];
    string output;
    for (int i = 1; s[i] != '\0'; i++)
    {
        if (s[i] == curr)
        {
            total++;
        }
        else
        {
            output += curr + to_string(total);
            total = 1;
            curr = s[i];
        }
    }

    output += curr + to_string(total);

    if (output.size() > s.size())
        return s;

    return output;
}

int main()
{
    string s;
    getline(cin, s);

    cout << compressString(s) << endl;

    return 0;
}
