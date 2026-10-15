vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> vis(n, 0);
    vector<int> ans;
    queue<int> q;

    q.push(0);
    vis[0] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto neighbours : adj[node])
        {
            if (!vis[neighbours])
            {
                vis[neighbours] = 1;
                q.push(neighbours);
            }
        }
    }
    return ans;
}