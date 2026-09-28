//There are 2 methods to printthis pattern : 

// #include <iostream>
// using namespace std;

// int main()
// {

//     int n;
//     int count = 1 ;
//     cout << "Enter The Number : ";
//     cin >> n;

// int row=1;

// while(row<=n){
//     int col=1;
//     while(col<=n){
//         char ch = 'A' + row + col - 2;
//         cout<< ch;
//         col = col + 1;
//     }
//     cout<< endl;
//     row = row + 1;
// }
//     return 0;
// }





#include <iostream>
using namespace std;

int main()
{

    int n;
    int count = 1 ;
    cout << "Enter The Number : ";
    cin >> n;

int row=1;

while(row<=n){
    int col=1;
    char start = 'A' + row - 1 ;
    while(col<=n){
        cout<< start <<" ";
        start = start + 1;
        col = col + 1;
    }
    cout<< endl;
    row = row + 1;
}
    return 0;
}