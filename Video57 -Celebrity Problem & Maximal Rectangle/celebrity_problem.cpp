class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {

        stack<int> st;
        int n = mat.size();

        // push all the people into the stack
        for (int i = n - 1; i >= 0; i--)
        {
            st.push(i);
        }
        int first, second;

        // find the candidate
        while (st.size() > 1)
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();

            // 10 case First knows second, so first cannot be a celebrity
            if (mat[first][second] && !mat[second][first])
                st.push(second);

            // 01 case Second knows first, so second cannot be a celebrity
            else if (!mat[first][second] && mat[second][first])
                st.push(first);

            // 11 case Both know each other, so neither can be a celebrity
            else if (mat[first][second] && mat[second][first])
                st.push(second);

            // 00 case Neither knows each other, so neither can be a celebrity
            else
                st.push(first);
        }

        if (st.empty())
        {
            return -1;
        }

        int num = st.top();
        st.pop();

        int row = 0, col = 0;

        // check if the candidate is a celebrity
        for (int i = 0; i < n; i++)
        {
            if (i != num)
            {
                row += mat[num][i];
                col += mat[i][num];
            }
        };

        return row == 0 && col == n - 1 ? num : -1;
    }
};