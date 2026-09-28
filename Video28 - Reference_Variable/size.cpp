#include<iostream>
using namespace std;

int main(){
char ch = 'q';
cout << "Size of char: " << sizeof(ch) << " bytes" << endl;

char* c = &ch;
cout << "Size of char*: " << sizeof(c) << " bytes" << endl;
}