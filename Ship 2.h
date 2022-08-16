//contents of CruiseShip.h

#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include <iostream>
#include <string>

using namespace std;

class CruiseShip : public Ship{
private:
    int maxPass;

public:
    //default constructor, which also calls
    //the default constructor of parent class
    CruiseShip() : Ship(){
        //set max number of passengers to 0
        maxPass = 0;
    }

    //overloaded constructor, which also calls
    //the overloaded constructor of parent class
    CruiseShip(int maxNum, string n, string y) :
        Ship(n, y){
        //check for invalid input of maximum
        //occupancy
        if(maxNum < 0){
            cout << "Error! Maximum number of passengers";
            cout << " cannot be negative!\n";
            cout << "Now terminating!\n";
            exit(EXIT_FAILURE);
        }

        //otherwise, store number in member variable
        maxPass = maxNum;
    }

    //accessor function
    int getMaxPassengers() const{
        return maxPass;
    }

    //mutator function
    void setMaxPassengers(int maxNum){
        //validate input using while loop
        while(maxNum < 0){
            cout << "Maximum number of passengers cannot";
            cout << " be negative number. Enter again: ";
            cin >> maxNum;
        }

        maxPass = maxNum;
    }

    //overridden print() function
    virtual void print() const{
        cout << "Name: " << name << endl;
        cout << "Max occupancy: " << maxPass << endl;
    }
};

#endif

