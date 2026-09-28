#include <iostream>
using namespace std;

void numToWord(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    n = n / 10;

    numToWord(n, arr);

    cout << arr[digit] << " ";
}

int main()
{

    int n;
    cout << "Enter the number : ";
    cin >> n;

    cout << endl;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    numToWord(n, arr);

    return 0;
}