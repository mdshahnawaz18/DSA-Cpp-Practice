#include<iostream>
using namespace std;

void update(int **p2){
    // p2 = p2 +1; //Value change nahi hogi


    *p2 = *p2 +1; //p2 change hoga
    
    
    // **p2 = **p2 +1; //i change hoga
}

int main(){
    int i = 5;
    int* p = &i;
    int** p2 = &p;

    cout<<"Before : "<<i<<endl;
    cout<<"Before : "<<p<<endl;
    cout<<"Before : "<<p2<<endl;

    update(p2);
    
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<p2<<endl;
    cout<<endl<<endl;

    return 0;

}