#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    int left = 0, right = m - 1,
        top = 0, bottom = n - 1;

    vector<int> ans = {};

    while (top <= bottom && left <= right)
    {
        // Traverse top-left to top-right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }

        top++;

        // Traverse top-right to bottom-right
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }

        right--;

        // Traverse bottom-right to bottom-left only if there is a row
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }

            bottom--;
        }

        // Traverse bottom-left to top-left only if there is a column
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }

            left++;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    vector<int> ans = spiralOrder(matrix);

    for (int n : ans)
    {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}
