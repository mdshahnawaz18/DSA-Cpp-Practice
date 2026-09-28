#include<iostream>
using namespace std;

int main(){

    int i= 5;

    //create a reference variable
    int &j = i;
    cout<<"Before"<<i<<endl;
    i++;
    cout<<"After"<<i<<endl;
    j++;
    cout<<"Reference variable j: "<<j<<endl;
    cout<<"Original variable i: "<<i<<endl;

}