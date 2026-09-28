class Solution
{
public:
    void rearrangeQueue(queue<int> &q)
    {
        // code here
        queue<int> newQue;

        int t = q.size() / 2;
        for (int i = 0; i < t; i++)
        {
            int val = q.front();
            q.pop();
            newQue.push(val);
        }

        while (!newQue.empty())
        {
            int val = newQue.front();
            newQue.pop();
            q.push(val);

            int element = q.front();
            q.pop();
            q.push(element);
        }
    }
};