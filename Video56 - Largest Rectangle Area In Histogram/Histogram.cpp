class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        stack<int> st;
        vector<int> Right(n);
        vector<int> Left(n);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                Right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
        {
            Right[st.top()] = n;
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                Left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            Left[st.top()] = -1;
            st.pop();
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int rectangle = heights[i] * (Right[i] - Left[i] - 1);
            ans = max(ans, rectangle);
        }
        return ans;
    }
};