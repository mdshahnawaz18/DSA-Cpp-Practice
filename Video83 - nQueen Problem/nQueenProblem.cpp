#include <bits/stdc++.h>
using namespace std;

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
    int x = row;
    int y = col;

    while (y >= 0)
    {
        if (Board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (Board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (Board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
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
            solve(col + 1, Board, ans, n);
            Board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> Board(n, vector<int>(n, 0));

    vector<vector<int>> ans;

    solve(0, Board, ans, n);

    return ans;
}