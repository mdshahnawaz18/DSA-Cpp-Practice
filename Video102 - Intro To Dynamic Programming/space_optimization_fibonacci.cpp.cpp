#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int curr = 1;
    int prev = 0;
    int sum;

    for (int i = 2; i <= n; i++)
    {
        sum = curr + prev;
        prev = curr;
        curr = sum;
    }

    cout << curr;

    return 0;
}