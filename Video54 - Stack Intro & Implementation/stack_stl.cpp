#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    s.push(24);
    s.push(42);
    s.push(64);
    s.push(72);

    s.pop();
    if(s.empty()){
        cout<<"It is empty "<<endl;
    }else{
        cout<<"It is not empty"<<endl;
    }
    
    cout<<"Top of the stack is : "<<s.top()<<endl;

    return 0;
}