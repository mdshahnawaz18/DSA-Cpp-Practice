#include<iostream>
using namespace std;

int main(){
    int arr[5] = {12,24,42,64,84};
    char ch[6] = "abcde";

    cout<<arr<<endl;
    //attention here
    cout<<ch<<endl;

    char *c = &ch[0];
    //prints entire string
    cout<<c<<endl;

    char temp = 'z';
    char *p = &temp;

    cout<<p<<endl;

    return 0;
}
