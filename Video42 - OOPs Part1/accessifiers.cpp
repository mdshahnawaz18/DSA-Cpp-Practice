//accessifiers

#include<iostream>
using namespace std;

class Hero{
    //properties
    private:
        int health;
        int attackPower;

    public:
        char level;

    //methods
    void print(){
        cout<<level<<endl;
        cout<<health<<endl;
        cout<<attackPower<<endl;
    }

    void setHealth(int h){
        health = h;
    }

    int getHealth(){
        return health;
    }

    void setAttackPower(int ap){
        attackPower = ap;
    }
    int getAttackPower(){
        return attackPower;
    }
};

int main(){
    
        //Static allocation
        Hero h1;
        // h1.level = 'A';
        // h1.setHealth(100); // Using the public method to set health
        // h1.setAttackPower(98); // Using the public method to set attack power
    
        // cout<<h1.getAttackPower()<<endl; // Using the public method to get attack power
        // cout<<h1.getHealth()<<endl; // Using the public method to get health
    
        h1.print();

    //Dynamic allocation
    Hero *d = new Hero; // Creating an object of the class Hero
    d->setHealth(100);
    d->level = 'S';
    d->setAttackPower(98);

    cout<<"level: "<<d->level<<endl; // Accessing the level property of the object d
    cout<<"health: "<<d->getHealth()<<endl; // Accessing the health property of the object d

    cout<<"level : "<<(*d).level<<endl; // Accessing the level property of the object d
    cout<<"health :"<<(*d).getHealth()<<endl;


    return 0;
}