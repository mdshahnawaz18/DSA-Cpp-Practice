#include <iostream>
using namespace std;

int firstOccurence(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }

        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOccurence(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }

        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{

    int even[12] = {1, 2, 3, 3, 3, 3, 3, 24, 46, 78, 82, 88};
    // int odd[11] = {2, 4, 5, 12, 35, 35, 35,35, 35, 125, 342};

    int first = firstOccurence(even, 12, 3);
    int last = lastOccurence(even, 12, 3);

    cout << "The element first position at " << first << endl;

    cout << "The element last position at " << last << endl;

    int totalOccurence = (last - first) + 1;
    cout<<"Total no. of occurence is "<<totalOccurence<<endl;


    return 0;
}
