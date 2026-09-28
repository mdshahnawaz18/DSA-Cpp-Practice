#include <iostream>
using namespace std;

void getMax(int arr[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "Maximum element is : " << max<<endl;
}


void getMin(int arr[], int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Minimum element is : " << min<<endl;
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

    getMin(number,n);

    return 0;
}