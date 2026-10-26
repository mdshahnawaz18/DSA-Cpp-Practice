#include <unordered_map>
#include <queue>
#include <list>

bool isCyclicGraph(int src, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbours : adj[front])
        {
            if (visited[neighbours] == true && neighbours != parent[front])
            {
                return true;
            }
            else if (!visited[neighbours])
            {
                q.push(neighbours);
                visited[neighbours] = true;
                parent[neighbours] = front;
            }
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
            bool ans = isCyclicGraph(i, adj, visited);
            if (ans)
            {
                return "Yes";
            }
        }
    }

    return "No";
}
