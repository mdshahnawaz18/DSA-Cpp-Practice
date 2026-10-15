#include <bits/stdc++.h>

bool isSafe(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n)
{
    if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && vis[x][y] == 0)
    {
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n, vector<string> &ans, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    // Down
    if (isSafe(x + 1, y, vis, arr, n))
    {
        solve(x + 1, y, vis, arr, n, ans, path + "D");
    }

    // Left
    if (isSafe(x, y - 1, vis, arr, n))
    {
        solve(x, y - 1, vis, arr, n, ans, path + "L");
    }

    // Right
    if (isSafe(x, y + 1, vis, arr, n))
    {
        solve(x, y + 1, vis, arr, n, ans, path + "R");
    }
    // Upper
    if (isSafe(x - 1, y, vis, arr, n))
    {
        solve(x - 1, y, vis, arr, n, ans, path + "U");
    }

    vis[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;

    if (n == 0 || arr[0][0] == 0 || arr[n - 1][n - 1] == 0)
    {
        return ans;
    }

    string path = "";
    vector<vector<bool>> vis(n, vector<bool>(n, 0));

    solve(0, 0, vis, arr, n, ans, path);
    return ans;
}