#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{

    int even[12] = {2, 3, 4, 5, 6, 12, 16, 24, 46, 78, 82, 88};
    int odd[11] = {2, 4, 5, 12, 24, 39, 47, 83, 124, 125, 342};

    int evenIndex = binarySearch(even, 12, 4);
    cout << "The element is at index " << evenIndex << endl;
    int oddIndex = binarySearch(odd, 11, 342);
    cout << "The element is at index " << oddIndex << endl;
}
