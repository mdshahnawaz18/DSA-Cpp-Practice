#include <iostream>
using namespace std;

int main()
{

    int n;
    int count = 1 ;
    cout << "Enter The Number : ";
    cin >> n;

int row=1;
char start = 'A';

while(row<=n){
    int col=1;
    while(col<=row){
        
        cout<< start;
        col = col + 1;
        start++;
    }
    cout<< endl;
    row = row + 1;
}
    return 0;
}