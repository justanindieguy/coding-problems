/*
 * You are given an integer N and a grid of size NxN.
 * The cells of the grid are numbered row wise from 1 to N^2. Rat wants to
 * travel from cell number 1 to cell number N^2, and it can move in only right
 * direction or down direction from a particular cell. There is exactly one path
 * from source to destination as some cells are blocked. Help the rap to find
 * the path.
 *
 * Input Format:
 *
 *   In the function an integer N is given, and a 2D vector consisting of only
 *   'O's and 'X's is given where 'X' represents blocked cell.
 *
 * Output Format:
 *
 *   Return a vector of cell numbers of cells in path (in sequence).
 *
 * Sample Testcase:
 *
 *   Input:
 *
 *   4
 *   O O X O
 *   O X O O
 *   O O O X
 *   X X O O
 *
 *   Output:
 *
 *   1 5 9 10 11 15 16
 */

#include <iostream>
#include <vector>

using namespace std;

int getCellNumber(int n, int i, int j)
{
    return n * i + j + 1;
}

bool traverseMaze(int n, vector<vector<char>> &maze, vector<int> &ans, int i = 0, int j = 0)
{
    int cell = getCellNumber(n, i, j);
    ans.push_back(cell);

    // Out of boundaries
    if (i == n || j == n)
    {
        ans.pop_back();
        return false;
    }

    // Rat has reached the exit
    if (i == n - 1 && j == n - 1)
    {
        return true;
    }

    // If path is blocked, remove cell from path and return false
    if (maze[i][j] == 'X')
    {
        ans.pop_back();
        return false;
    }

    // First try to go to the bottom, then to the right
    return traverseMaze(n, maze, ans, i + 1, j) || traverseMaze(n, maze, ans, i, j + 1);
}

vector<int> findPath(int n, vector<vector<char>> &maze)
{
    vector<int> ans = {};
    traverseMaze(maze.size(), maze, ans);
    return ans;
}

int main()
{
    vector<vector<char>> maze = {
        {'O', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O'},
        {'O', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'O'},
    };

    vector<int> ans = findPath(maze.size(), maze);

    for (int cell : ans)
    {
        cout << cell << " ";
    }

    cout << endl;

    return 0;
}
