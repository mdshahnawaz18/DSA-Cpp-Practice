#include<iostream>
using namespace std;

int score = 15;

void a(int& i){
    cout<<"Score is : "<<score<<" in a"<<endl;
    score++;
    cout<<i<<endl;
    // b(i);
}

void b(int& i){
    cout<<"Score is : "<<score<<" in b"<<endl;
    cout<<i<<endl;
}

int main(){
    cout<<"Score is : "<<score<<"in main"<<endl;
    
    int i = 5;
    a(i);
    b(i);

    return 0;
}