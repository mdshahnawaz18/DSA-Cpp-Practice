#include <algorithm>

int getKthLargest(vector<int> &arr, int k)
{
    // code here
    // priority_queue<int , vector<int> , greater<int>> mini;

    int n = arr.size();
    vector<int> subArray;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            subArray.push_back(sum);
        }
    }

    sort(subArray.begin(), subArray.end());

    int m = subArray.size();
    return subArray[m - k];
}