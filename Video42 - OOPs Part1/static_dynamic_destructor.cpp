#include<iostream>
using namespace std;

class Hero {

public:

    // Default Constructor
    Hero() {
        cout << "Constructor Called" << endl;
    }

    // Destructor
    ~Hero() {
        cout << "Destructor Called" << endl;
    }

};

int main() {

    // Static Object
    Hero hero1;

    cout << endl;

    // Dynamic Object
    Hero *hero2 = new Hero();

    cout << endl;

    // Manual Destructor Call
    delete hero2;

    cout << endl;

    cout << "End of Program" << endl;

    return 0;
}