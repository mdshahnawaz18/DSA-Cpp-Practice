#include<iostream>
using namespace std;

int power(int a , int b){

    if(b == 0){
        return 1;
    }

    return a*power(a , b - 1);
}

int main(){
    int a , b;
    cout<<"Enter the value of a and b : "<<endl;
    cin>>a>>b;

    cout<<"power("<<a<<" , "<<b<<") is "<<power(a , b);

    return 0;
}