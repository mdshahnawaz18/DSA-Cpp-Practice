#include<iostream>
#include<cstring>
using namespace std;

class Hero {

private:
    int health;

public:
    char *name;
    char level;

    // Static Variable
    static int timeToComplete;

    // Default Constructor
    Hero() {
        cout << "Default Constructor Called" << endl;
        name = new char[100];
    }

    // Parameterized Constructor
    Hero(int health) {

        name = new char[100];
        this->health = health;
    }

    Hero(int health, char level) {

        name = new char[100];
        this->health = health;
        this->level = level;
    }

    // Copy Constructor
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

    // Getter
    int getHealth() {
        return health;
    }

    // Print
    void print() {

        cout << endl;
        cout << "[ Name : " << name;
        cout << " , Health : " << health;
        cout << " , Level : " << level << " ]";
        cout << endl;
    }

    // Static Function
    static int random() {
        return timeToComplete;
    }

    // Destructor
    ~Hero() {
        cout << "Destructor Called" << endl;
    }

};

int Hero::timeToComplete = 5;

int main() {

    cout << "===== Static Member =====\n";
    cout << Hero::random() << endl;

    cout << "\n===== Default Constructor =====\n";
    Hero hero1;

    hero1.setHealth(100);
    hero1.setLevel('A');

    char name[] = "Babbar";
    hero1.setName(name);

    hero1.print();

    cout << "\n===== Parameterized Constructor =====\n";

    Hero hero2(90,'B');

    char name2[] = "Love";
    hero2.setName(name2);

    hero2.print();

    cout << "\n===== Copy Constructor =====\n";

    Hero hero3(hero1);

    hero3.print();

    cout << "\n===== Dynamic Object =====\n";

    Hero *hero4 = new Hero();

    delete hero4;

    return 0;
}