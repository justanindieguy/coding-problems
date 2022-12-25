#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char *mystrtok(char *str, char delim)
{
    static char *input = NULL;
    if (str != NULL)
    {
        input = str;
    }

    if (input == NULL)
    {
        return NULL;
    }

    char *token = new char[strlen(input) + 1];
    int i = 0;
    for (; input[i] != '\0'; i++)
    {
        if (input[i] != delim)
        {
            token[i] = input[i];
        }
        else
        {
            token[i] = '\0';
            input += i + 1;
            return token;
        }
    }

    // Out of the loop
    token[i] = '\0';
    input = NULL;

    return token;
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);

    /* Internally maintains the state of the string you passed in the
       last fn call (static variable). */

    cout << "My strtok:" << endl;
    char *token = mystrtok(input, ' ');
    while (token != NULL)
    {
        cout << token << endl;
        token = mystrtok(NULL, ' ');
    }

    cout << endl;

    cout << "strtok:" << endl;
    char *newToken = strtok(input, " ");
    while (newToken != NULL)
    {
        cout << newToken << endl;
        newToken = strtok(NULL, " ");
    }

    return 0;
}
