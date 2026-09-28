#include <iostream>
using namespace std;

int peakMountain(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }

        else
        {
            end = mid;
        }

        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{

    int even[10] = {1, 2, 3, 22, 20, 12, 7, 4, 1, 0};
    int odd[11] = {2, 4, 5, 12, 24, 35, 16, 12, 7, 5, 2};

    cout << "The peak element is at " << peakMountain(even, 10) << endl;

    cout << "The peak element is at " << peakMountain(odd, 11) << endl;

    return 0;
}
