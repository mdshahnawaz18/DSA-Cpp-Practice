#include<iostream>
#include<cstring>
using namespace std;

class Hero {

    // Private Property
    private:
    int health;

    // Public Property
    public:
    char *name;
    char level;

    // Constructor
    Hero() {
        name = new char[100];
    }

    // Parameterized Constructor (Health)
    Hero(int health) {

        name = new char[100];

        this->health = health;
    }

    // Parameterized Constructor (Health + Level)
    Hero(int health, char level) {

        name = new char[100];

        this->health = health;
        this->level = level;
    }

    // Print
    void print() {

        cout << endl;

        cout << "[ Name : " << name;
        cout << " , Health : " << health;
        cout << " , Level : " << level << " ]";

        cout << endl;
    }

    // Setter
    void setName(char name[]) {
        strcpy(this->name, name);
    }

};

int main() {

    // Object using Constructor 1
    Hero hero1(80);

    char name1[] = "Babbar";
    hero1.setName(name1);

    hero1.print();


    // Object using Constructor 2
    Hero hero2(95,'A');

    char name2[] = "Love";
    hero2.setName(name2);

    hero2.print();

    return 0;
}