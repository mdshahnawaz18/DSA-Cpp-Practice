#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        // code here
        priority_queue<int> heap;

        for (int i = 0; i < k; i++)
        {
            heap.push(arr[i]);
        }

        int n = arr.size();
        for (int i = k; i < n; i++)
        {
            if (arr[i] < heap.top())
            {
                heap.pop();
                heap.push(arr[i]);
            }
        }

        int ans = heap.top();
        return ans;
    }
};