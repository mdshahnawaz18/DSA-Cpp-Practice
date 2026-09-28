#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n<=1){
        return false;dx
    }
    for (int i=2 ; i<n ; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){

int n;
cout<<"Write a Number : ";
cin>>n;

if(isPrime(n)){
    cout<<"It is a prime no."<<endl;
}
else{
    cout<<"It is not a prime no."<<endl;
}
}