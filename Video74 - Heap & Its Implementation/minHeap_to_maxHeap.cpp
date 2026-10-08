
void heapify(long *arr, int n, int i)
{
    int largest = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

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

void minHeapToMaxHeap(long *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}