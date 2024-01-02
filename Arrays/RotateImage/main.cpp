/*
 * You are given an n*n 2D matrix representing an image, rotate the image by
 * 90 degrees (clockwise).
 *
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (vector<int> row : matrix)
    {
        for (int val : row)
        {
            cout << val << ", ";
        }

        cout << endl;
    }
}

void rotateImage(vector<vector<int>> &matrix)
{
    int n = matrix.size(),
        left = 0, right = n - 1;

    while (left < right)
    {
        for (int i = 0; i < right - left; i++)
        {
            int top = left, bottom = right;
            int topLeftValue = matrix[top][left + i];

            // Move bottom-left into top-left
            matrix[top][left + i] = matrix[bottom - i][left];

            // Move bottom-right into bottom-left
            matrix[bottom - i][left] = matrix[bottom][right - i];

            // Move top-right into bottom-right
            matrix[bottom][right - i] = matrix[top + i][right];

            // Move top-left into top-right
            matrix[top + i][right] = topLeftValue;
        }

        left++;
        right--;
    }
}

int main()
{
    vector<vector<int>> m1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    vector<vector<int>> m2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16},
    };

    cout << "First matrix:" << endl;
    printMatrix(m1);
    cout << "----------" << endl;
    rotateImage(m1);
    printMatrix(m1);

    cout << "Second matrix:" << endl;
    printMatrix(m2);
    cout << "----------" << endl;
    rotateImage(m2);
    printMatrix(m2);

    return 0;
}
