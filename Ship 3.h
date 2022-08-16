//contents of CargoShip.h

#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include <iostream>
#include <string>

using namespace std;

class CargoShip : public Ship{
private:
    int maxTonnage;

public:
    //default constructor, which will also
    //call default constructor of parent class
    CargoShip() : Ship(){
        //set maximum capacity to 0
        maxTonnage = 0;
    }

    //overloaded constructor
    CargoShip(int maxCap, string n, string y) :
        Ship(n, y){
        //check for invalid input for maximum
        //capacity
        if(maxCap < 0){
            cout << "Error! Maximum capacity cannot be";
            cout << " negative number!\n";
            cout << "Now terminating!\n";
            exit(EXIT_FAILURE);
        }

        //otherwise, store the value in the member
        //variable
        maxTonnage = maxCap;
    }

    //accessor function
    int getMaxCapacity() const{
        return maxTonnage;
    }

    //mutator function
    void setMaxCapacity(int maxCap){
        //validate input using while loop
        while(maxCap < 0){
            cout << "Maximum capacity cannot be negative number!";
            cout << " Enter again: ";
            cin >> maxCap;
        }

        maxTonnage = maxCap;
    }

    //overridden print() function
    virtual void print() const{
        cout << "Name: " << name << endl;
        cout << "Max Capacity: " << maxTonnage << endl;
    }

};

#endif

