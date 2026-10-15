#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

void makeAdjList(unordered_map<int, set<int>> &adj, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void dfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &vis, vector<int> &component, int node)
{
    vis[node] = true;

    component.push_back(node);

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(adj, vis, component, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, bool> vis;
    unordered_map<int, set<int>> adj;
    vector<vector<int>> ans;

    makeAdjList(adj, edges);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> component;
            dfs(adj, vis, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}