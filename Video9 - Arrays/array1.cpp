#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int first[5];
    // cout<<first[3];
    // int n=5;

    int second[10] = {0};
    int third[8] = {1};
    int fourth[20] = {2, 4, 5, 7, 8, 9};
    cout<<sizeof(fourth)/sizeof(int)<<endl;

    char box[5] = {'a', 'b', 'c', 'd', 'e'};
    float floNum[6];
    double dubNum[6];

    for (int i = 0; i < 5; i++)
    {
        cout << box[i] << " ";
    }

    // printArray(first, 5);
    // printArray(second, 10);
    // printArray(third, 8);
    // printArray(fourth, 20);
}