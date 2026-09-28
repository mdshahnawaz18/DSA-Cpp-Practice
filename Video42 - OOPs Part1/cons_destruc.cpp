#include<iostream>
using namespace std;

//constructor and destructor
class Hero{
    //properties
    private:
        int health;

    public:
        char level;

    //methods
    Hero(int health){ //constructor
        this->health = health;
    }

    Hero(int health , char level){
        this->health = health;
        this->level = level;
    }

    ~Hero(){ //destructor
    }

    void print(){
        cout<<level<<endl;
        cout<<health<<endl;
    }

    int getHealth(){
        return health;
    }

    void setHealth(int h){
        health = h;
    }
};


int main(){
    
// Hero h1; // Creating an object of the class Hero

// h1.health = 100;
// h1.level = 'A';
// h1.print();

Hero shahnawaz(84);
shahnawaz.print();

Hero *h = new Hero(12);
h->print();

Hero temp(22, 'B');
temp.print();

//write a copy constructor
temp.level = shahnawaz.level;

cout<<temp.level<<endl;

return 0;
}