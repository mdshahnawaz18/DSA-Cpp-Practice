#include<iostream>
using namespace std;

int getPivot(int arr[], int n)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] > arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int binarySearch(int arr[], int start, int end, int key)
{

    int s = start;
    int e = end;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{

    int arr[6] = {7, 8, 12, 14, 24, 25};
    int n = 6;
    int k = 24;

    int pivot = getPivot(arr, n);

    if (arr[pivot] < k && k < arr[n - 1])
    {
        cout<<"Index "<< binarySearch(arr, pivot, n - 1, k);
    }
    else
    {
        cout<<"Index "<< binarySearch(arr, 0, pivot - 1, k);
    }

    return 0;
}
