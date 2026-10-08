class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> mini;

        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            mini.push(arr[i]);
        }

        int sum = 0;
        int cost = 0;

        while (mini.size() > 1)
        {

            int a = mini.top();
            mini.pop();
            int b = mini.top();
            mini.pop();

            sum = a + b;
            cost += sum;
            mini.push(sum);
        }
        return cost;
    }
};