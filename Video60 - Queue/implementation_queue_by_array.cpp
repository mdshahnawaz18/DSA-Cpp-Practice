#include <bits/stdc++.h>
class Queue
{
    int *arr;
    int qFront;
    int rear;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        size = 110000;
        arr = new int[size];

        qFront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (qFront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (rear == size)
        {
            return;
        }
        else
        {
            arr[rear] = data;
            rear = rear + 1;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (qFront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qFront];

            arr[qFront] = -1;
            qFront++;
            if (qFront == rear)
            {
                qFront = 0;
                rear = 0;
            }

            return ans;
        }
    }

    int front()
    {
        // Implement the front() function
        if (qFront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qFront];
        }
    }
};