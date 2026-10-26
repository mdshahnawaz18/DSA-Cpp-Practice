
#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

void dfs(int node, int parent, unordered_map<int, list<int>> &adj, int &timer,
         unordered_map<int, bool> &vis,
         vector<int> &disc, vector<int> &low, vector<int> &ap)
{

    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }

        if (!vis[nbr])
        {
            dfs(nbr, node, adj, timer, vis, disc, low, ap);

            low[node] = min(low[node], low[nbr]);

            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int n, e;
        cin >> n >> e;

        vector<pair<int, int>> edges;

        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back(make_pair(u, v));
        }

        unordered_map<int, list<int>> adj;

        for (int i = 0; i < e; i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer = 0;
        vector<int> disc(n + 1, -1);
        vector<int> low(n + 1, -1);
        unordered_map<int, bool> vis;
        vector<int> ap(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, timer, vis, disc, low, ap);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (ap[i] != 0)
            {
                cout << i << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
