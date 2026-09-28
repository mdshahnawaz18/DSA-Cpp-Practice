#include <iostream>
using namespace std;

void print(int *p)
{
    cout << "Inside print: " << p << endl;
}

void update(int *p)
{
    // p = p + 1;
    // cout << "Inside update: " << p << endl;
    *p = *p + 1;
    cout << "Inside update: " << *p << endl;
}

int getSum(int *arr, int n)
{
    cout<<endl<<"Size of arr is : "<<sizeof(arr)<<endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += i[arr];
    }
    return sum;
}

// int getSum(int arr[], int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }
//     return sum;
// }


int main()
{
    // int value = 5;
    // int *p = &value;

    // print(p);

    // cout << "Before : " << p << endl;
    // update(p);
    // cout << "After : " << p << endl;


    // cout << "Before : " << *p << endl;
    // update(p);
    // cout << "After : " << *p << endl;

    int arr[5] = {1, 2, 3, 4, 5};
    cout<<"Sum is : "<<getSum(arr, 5)<<endl;

    return 0;
}
