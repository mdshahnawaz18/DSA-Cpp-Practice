#include <iostream>
using namespace std;

void getMax(int arr[], int size)
{
    int maxiNum = INT_MIN;
    for (int i = 0; i < size; i++)
    {

        maxiNum = max(maxiNum, arr[i]);
    }
    cout << "Maximum element is : " << maxiNum << endl;
}

void getMin(int arr[], int size)
{
    int miniNum = INT_MAX;
    for (int i = 0; i < size; i++)
    {

        miniNum = min(miniNum, arr[i]);
    }
    cout << "Minimum element is : " << miniNum << endl;
}

int main()
{

    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    int number[100];
    cout << "Enter the value of array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }

    getMax(number, n);

    getMin(number, n);

    return 0;
}