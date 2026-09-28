#include<iostream>
using namespace std;

int main(){
    // int arr[10] = {24,42,64,84};

    // int temp[10] = {1,2};
    // cout<<"1st no. is : "<<sizeof(temp)<<endl;
    // cout<<"1st no. is : "<<sizeof(*temp)<<endl;
    // cout<<"1st no. is : "<<sizeof(&temp)<<endl;

    // int *ptr = &temp[0];
    // cout<<"Size : "<<sizeof(ptr)<<endl;
    // cout<<"Size : "<<sizeof(*ptr)<<endl;
    // cout<<"Size : "<<sizeof(&ptr)<<endl;

    int a[20] = {1,2,3,4,5};

    cout<<"->"<<&a[0]<<endl; 
    cout<<"->"<<&a<<endl; 
    cout<<"->"<<a<<endl; 
    
    cout<<"Below are P ->"<<endl;
    
    int *p = &a[0];
    cout<<"->"<<p<<endl;
    cout<<"->"<<*p<<endl;
    cout<<"->"<<&p<<endl;
    

    cout<<"Error Code"<<endl;
    int arr[10];

    // arr = arr+1;

    int *ptr = &arr[0];
    
    cout<<"->"<<ptr<<endl;
    ptr = ptr+1;
    cout<<"->"<<ptr<<endl;


    return 0;
}
