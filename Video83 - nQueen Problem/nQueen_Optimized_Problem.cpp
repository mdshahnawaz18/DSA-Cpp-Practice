#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperDiagonalCheck;
unordered_map<int, bool> lowerDiagonalCheck;

void addToSolution(vector<vector<int>> &Board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(Board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &Board, int n)
{
    if (rowCheck[row] == true)
    {
        return false;
    }

    if (upperDiagonalCheck[n - 1 + col - row] == true)
    {
        return false;
    }
    if (lowerDiagonalCheck[row + col] == true)
    {
        return false;
    }
    return true;
}

void solve(int col, vector<vector<int>> &Board, vector<vector<int>> &ans, int n)
{
    if (col == n)
    {
        addToSolution(Board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, Board, n))
        {
            Board[row][col] = 1;

            rowCheck[row] = true;
            upperDiagonalCheck[n - 1 + col - row] = true;
            lowerDiagonalCheck[row + col] = true;

            solve(col + 1, Board, ans, n);

            Board[row][col] = 0;

            rowCheck[row] = false;
            upperDiagonalCheck[n - 1 + col - row] = false;
            lowerDiagonalCheck[row + col] = false;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> Board(n, vector<int>(n, 0));

    vector<vector<int>> ans;

    solve(0, Board, ans, n);

    return ans;
}