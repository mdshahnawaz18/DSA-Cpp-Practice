#include<iostream>
using namespace std;

class Hero {

public:

    // Static Variable
    static int timeToComplete;

    // Static Function
    static int random() {
        return timeToComplete;
    }

};

// Static Variable Initialization
int Hero::timeToComplete = 5;

int main() {

    // Access using Class Name
    cout << Hero::timeToComplete << endl;
    cout << Hero::random() << endl;

    cout << endl;

    // Access using Object
    Hero hero1;

    cout << hero1.timeToComplete << endl;

    cout << endl;

    // Change Static Variable
    Hero hero2;
    hero2.timeToComplete = 10;

    cout << hero1.timeToComplete << endl;
    cout << hero2.timeToComplete << endl;

    cout << Hero::random() << endl;

    return 0;
}