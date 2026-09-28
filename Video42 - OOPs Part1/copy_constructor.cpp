#include<iostream>
#include<cstring>
using namespace std;

class Hero {

private:
    int health;

public:
    char *name;
    char level;

    // Default Constructor
    Hero() {
        cout << "Default Constructor Called" << endl;
        name = new char[100];
    }

    // Copy Constructor (Deep Copy)
    Hero(Hero &temp) {

        cout << "Copy Constructor Called" << endl;

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);

        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
    }

    // Setter
    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    // Print
    void print() {

        cout << endl;
        cout << "[ Name : " << name;
        cout << " , Health : " << health;
        cout << " , Level : " << level << " ]";
        cout << endl;
    }

};

int main() {

    // Original Object
    Hero hero1;

    hero1.setHealth(100);
    hero1.setLevel('A');

    char name[] = "Babbar";
    hero1.setName(name);

    // Copy Constructor
    Hero hero2(hero1);

    cout << "\nBefore Changing\n";

    hero1.print();
    hero2.print();

    // Original Object Change
    hero1.name[0] = 'G';

    cout << "\nAfter Changing hero1\n";

    hero1.print();
    hero2.print();

    // Assignment Operator
    hero1 = hero2;

    cout << "\nAfter Assignment\n";

    hero1.print();
    hero2.print();

    return 0;
}