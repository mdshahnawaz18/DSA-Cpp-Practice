#include <algorithm>
#include <limits.h>
#include <queue>

class node
{
public:
    int data, rows, cols;

    node(int d, int i, int j)
    {
        this->data = d;
        rows = i;
        cols = j;
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

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];

        mini = min(mini, element);
        maxi = max(maxi, element);

        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int endi = maxi;

    while (!minHeap.empty())
    {
        node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if (maxi - mini < endi - start)
        {
            start = mini;
            endi = maxi;
        }

        if (temp->cols + 1 < n)
        {
            maxi = max(maxi, a[temp->rows][temp->cols + 1]);
            minHeap.push(new node(a[temp->rows][temp->cols + 1], temp->rows, temp->cols + 1));
        }
        else
        {
            break;
        }
    }
    return (endi - start + 1);
}