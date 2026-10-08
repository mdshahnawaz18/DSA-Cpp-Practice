#include <iostream>
using namespace std;

class Student
{
public:
    int arr[100];
    int size;

    Student()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void deleteHeapNode()
    {
        if (size == 0)
        {
            cout << "Nothing To Delete " << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        int largest = i;

        while (i <= size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex <= size && arr[largest] < arr[leftIndex])
            {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[largest] < arr[rightIndex])
            {
                largest = rightIndex;
            }
            if (largest == i)
            {
                return;
            }

            swap(arr[largest], arr[i]);
            i = largest;
        }
    }
};

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

int main()
{
    Student s;
    s.insert(54);
    s.insert(52);
    s.insert(58);
    s.insert(57);
    s.insert(53);
    s.insert(12);
    s.insert(2);
    s.insert(18);
    s.insert(24);
    s.insert(48);
    s.print();

    cout << endl;

    // s.deleteHeapNode();
    // s.print();

    int arr[10] = {-1, 45, 12, 5, 6, 7, 8, 9, 11, 15};
    int n = 9;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array now " << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}