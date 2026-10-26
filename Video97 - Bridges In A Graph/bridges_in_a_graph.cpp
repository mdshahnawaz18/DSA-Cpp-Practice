#include <unordered_map>
#include <list>
#include <vector>

void dfs(int node, int parent, unordered_map<int, list<int>> &adj, int &timer,
         unordered_map<int, bool> &vis,
         vector<int> &disc, vector<int> &low, vector<vector<int>> &result)
{

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }

        if (!vis[nbr])
        {
            dfs(nbr, node, adj, timer, vis, disc, low, result);

            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, adj, timer, vis, disc, low, result);
        }
    }
    return result;
}