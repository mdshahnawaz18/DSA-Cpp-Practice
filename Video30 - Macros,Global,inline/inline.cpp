#include<iostream>
using namespace std;

int getMax(int& a,int& b){
    return (a > b) ? a : b ;
}

int main(){
    int a=1, b=2;
    int ans = 0;

    ans = getMax(a,b);
    cout<<ans<<endl;

    a=a+1;
    b=b+4;

    ans = getMax(a,b);
    cout<<ans<<endl;

    return 0;
}