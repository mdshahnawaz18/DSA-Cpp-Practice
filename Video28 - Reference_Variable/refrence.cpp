#include<iostream>
using namespace std;

int& func(int a){ //Bad Practice : Returning reference of local variable 
    int num = a;
    int& ans = num;
    return ans;
}

int* funptr(int a){ //Bad Practice : Returning pointer of local variable
    int num = a;
    int* ptr = &num;
    return ptr;
}

void update1(int n){
    n++;
}
void update2(int &n){
    n++;
}

int main(){

    int n = 5;


    // update1(n);
    // cout << "After update1: " << n << endl;
    // update2(n);
    // cout << "After update2: " << n << endl;

    cout<<"Func value : "<<func(n)<<endl;
    cout<<"Funptr value : "<<funptr(n)<<endl;

    return 0;
}