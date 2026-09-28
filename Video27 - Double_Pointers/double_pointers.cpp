#include<iostream>
using namespace std;

int main(){
    int i = 5;
    int *p = &i;
    int **p2 = &p;

    //Value of i
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;

    //Address of i
    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;

    //Address of p
    cout<<&p<<endl;
    cout<<p2<<endl;


    return 0;

}