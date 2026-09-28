#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int i = 0;
    int sum = 0;
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            sum = sum + i;
        }
        i++;
    }
    cout << "Sum of All Even No. = " << sum;

    return 0;
}