#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    if (leftIndex < n && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }

    if (rightIndex < n && arr[rightIndex] > arr[largest])
    {
        largest = rightIndex;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[10] = {-1, 45, 12, 5, 6, 7, 8, 9, 11, 15};
    int n = 9;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array now " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "Printing Array After Heap Sort " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}