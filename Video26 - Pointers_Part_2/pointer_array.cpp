#include<iostream>
using namespace std;

int main(){
    int arr[10] = {24,42,64,84};

    cout<<"address of first memeory block is "<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"address of first memeory block is "<<&arr[0]<<endl;

    cout<<"4th : "<<*arr<<endl;
    cout<<"6th : "<<*arr + 1<<endl;
    cout<<"7th : "<<*(arr + 1)<<endl;
    cout<<"8th : "<<arr[2]<<endl;
    cout<<"9th : "<<*(arr+2)<<endl;

    int i = 2;
    cout<<i[arr]<<endl;

    return 0;
}
