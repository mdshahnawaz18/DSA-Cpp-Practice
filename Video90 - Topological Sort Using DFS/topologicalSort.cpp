#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <stack>

void topoSort(int node, stack<int> &s, vector<bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neighbours : adj[node])
    {
        if (!visited[neighbours])
        {
            topoSort(neighbours, s, visited, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v, false);
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSort(i, s, visited, adj);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}