#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#include <list>

bool detectCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbours : adj[node])
    {
        if (!visited[neighbours])
        {
            bool solution = detectCycleDFS(neighbours, visited, dfsVisited, adj);
            if (solution)
            {
                return true;
            }
        }
        else if (dfsVisited[neighbours])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            bool ans = detectCycleDFS(i, visited, dfsVisited, adj);
            if (ans == true)
            {
                return true;
            }
        }
    }
    return false;
}
