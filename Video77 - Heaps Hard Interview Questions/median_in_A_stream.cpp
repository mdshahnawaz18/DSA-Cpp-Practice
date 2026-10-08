#include <bits/stdc++.h>
using namespace std;

int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void getMedian(int arr,
               priority_queue<int> &maxi,
               priority_queue<int, vector<int>, greater<int>> &mini,
               int &median)
{

    switch (signum(maxi.size(), mini.size()))
    {
    case 0:
        if (arr > median)
        {
            mini.push(arr);
            median = mini.top();
        }
        else
        {
            maxi.push(arr);
            median = maxi.top();
        }
        break;
    case 1:
        if (arr > median)
        {
            mini.push(arr);
            median = (maxi.top() + mini.top()) / 2;
        }
        else
        {
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(arr);
            median = (maxi.top() + mini.top()) / 2;
        }
        break;
    case -1:
        if (arr > median)
        {
            maxi.push(mini.top());
            mini.pop();
            mini.push(arr);
            median = (maxi.top() + mini.top()) / 2;
        }
        else
        {
            maxi.push(arr);
            median = (maxi.top() + mini.top()) / 2;
        }
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> ans;

    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    int median = 0;

    for (int i = 0; i < n; i++)
    {
        getMedian(arr[i], maxi, mini, median);
        ans.push_back(median);
    }
    return ans;
}
