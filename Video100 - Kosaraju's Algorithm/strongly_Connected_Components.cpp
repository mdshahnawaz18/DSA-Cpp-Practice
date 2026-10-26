class Solution
{
public:
    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[node] = true;

        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                dfs(nbr, vis, st, adj);
            }
        }

        st.push(node);
    }

    void revDFS(int top, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose)
    {
        vis[top] = true;

        for (auto nbr : transpose[top])
        {
            if (!vis[nbr])
            {
                revDFS(nbr, vis, transpose);
            }
        }
    }

    int countSCC(vector<vector<int>> &adj)
    {
        unordered_map<int, bool> vis;
        stack<int> st;
        int n = adj.size();
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }

        unordered_map<int, list<int>> transpose;
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;

            for (auto nbr : adj[i])
            {
                transpose[nbr].push_back(i);
            }
        }

        int count = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if (!vis[top])
            {
                count++;
                revDFS(top, vis, transpose);
            }
        }

        return count;
    }
};
