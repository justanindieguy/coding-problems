/*
 * You are given a M x N matrix which is row wise and column wise sorted.
 * You have to search the index of the given integer K in the matrix.
 *
 * Input Format:
 *
 * Function contains integer M, integer N, 2D vector containing integers and an
 * integer k.
 *
 * Output Format:
 *
 * Return a pair of integers {x, y} where x is the row index and y is column
 * index of k in the matrix.
 *
 * Expected Complexity: Linear
 */

#include <iostream>
#include <vector>

using namespace std;

// Brute Force - O(N*M)
pair<int, int> staircaseSearchBrute(vector<vector<int>> matrix, int k)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        int m = matrix[i].size();
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == k)
                return {i, j};
        }
    }

    return {-1, -1};
}

// Linear Solution - O(N+M)
pair<int, int> staircaseSearchLinear(vector<vector<int>> matrix, int k)
{
    int rows = matrix.size(),
        cols = matrix[0].size(),
        row = 0, col = cols - 1;

    while (row < rows && col > -1)
    {
        int curr = matrix[row][col];

        if (curr == k)
            return {row, col};

        if (k > curr)
            row++;
        else
            col--;
    }

    return {-1, -1};
}

// Binary Search Best! - O(log N + M)
pair<int, int> staircaseBinarySearch(vector<vector<int>> matrix, int k)
{
    int rows = matrix.size(),
        cols = matrix[0].size(),
        start = 0, end = rows * cols - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2,
            rowIdx = mid / cols, colIdx = mid % cols,
            num = matrix[rowIdx][colIdx];

        if (num == k)
            return {rowIdx, colIdx};

        if (num > k)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return {-1, -1};
}

int main()
{
    /*
     * The first integer of each row is greater than the last integer
     * of the previous row.
     */

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
    };

    int k;
    cin >> k;

    pair<int, int> p = staircaseBinarySearch(matrix, k);
    cout << "{" << p.first << ", " << p.second << "}" << endl;

    return 0;
}
