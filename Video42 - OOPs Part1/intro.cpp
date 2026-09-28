#include<iostream>
using namespace std;

//creation of object
class Hero{
    //properties
    public:
        int health;
        char level;

    //methods
    void print(){
        cout<<level<<endl;
        cout<<health<<endl;
    }
};


int main(){
    Hero h1; // Creating an object of the class Hero

    cout<<"Size of h1: "<<sizeof(h1)<<endl;
    cout<<h1.health<<endl; // Accessing the health property of the object h1
    cout<<h1.level<<endl; // Accessing the level property of the object h1
    
    h1.health = 100;
    h1.level = 'A';
    h1.print();

    return 0;
}