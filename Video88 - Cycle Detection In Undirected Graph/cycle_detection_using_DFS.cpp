#include <unordered_map>
#include <list>

bool isCyclicDFS(int src, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{

    visited[src] = true;

    for (auto neighbours : adj[src])
    {
        if (!visited[neighbours])
        {
            bool ans = isCyclicDFS(neighbours, src, adj, visited);
            if (ans == true)
            {
                return true;
            }
        }
        else if (neighbours != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, -1, adj, visited);
            if (ans == true)
            {
                return "Yes";
            }
        }
    }

    return "No";
}
