#include <bits/stdc++.h>
#include <queue>

class node
{
public:
    int data;
    int i;
    int j;

    node(int data, int i, int j)
    {
        this->data = data;
        this->i = i;
        this->j = j;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        if (kArrays[i].size() > 0)
        {
            node *temp = new node(kArrays[i][0], i, 0);
            minHeap.push(temp);
        }
    }

    vector<int> ans;

    while (minHeap.size() > 0)
    {
        node *top = minHeap.top();
        minHeap.pop();

        ans.push_back(top->data);

        int i = top->i;
        int j = top->j;

        if (j + 1 < kArrays[i].size())
        {
            node *temp = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(temp);
        }
    }
    return ans;
}
