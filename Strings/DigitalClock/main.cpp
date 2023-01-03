#include <iostream>
#include <string>

using namespace std;

string applyTimeFormat(int n)
{
    string time = to_string(n);

    if (n < 10)
        return "0" + time;

    return time;
}

string convertToDigitalTime(int rawMinutes)
{
    string hours = to_string(rawMinutes / 60);
    string minutes = applyTimeFormat(rawMinutes % 60);
    return hours + ":" + minutes;
}

int main()
{
    int rawMinutes;
    cin >> rawMinutes;
    cout << convertToDigitalTime(rawMinutes) << endl;

    return 0;
}
