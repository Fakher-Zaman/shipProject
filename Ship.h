//contents of Ship.h

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Ship{
protected:
    string name;
    string year;

public:
    //default constructor
    Ship(){
        //set name and year to some
        //initial values
        name = "";
        year = "1950";
    }

    //overloaded constructor
    Ship(string n, string y){
        //check for invalid input
        if(n.size() == 0){
            cout << "Error! Name cannot be empty!\n";
            cout << "Now terminating!\n";
            exit(EXIT_FAILURE);
        }

        //if name is not empty, save it in member variable
        name = n;

        if(y.size() == 0){
            cout << "Error! Build year cannot be empty!\n";
            cout << "Now terminating!\n";
            exit(EXIT_FAILURE);
        }

        //first convert the year from string to
        //integer to perform further checking
        int yr = atoi(y.c_str());

        if(yr < 1700){
            cout << "Error! Build year cannot be less";
            cout << " than 1700!\nNow terminating!\n";
            exit(EXIT_FAILURE);
        }

        //otherwise, set the construction year
        year = y;
    }

    //accessor functions
    string getName() const{
        return name;
    }

    string getYear() const{
        return year;
    }

    //mutator functions
    void setName(string n){
        //validate input
        if(n.size() == 0){
            cout << "Name cannot be empty!";
            cout << " Enter again: ";
            cin >> n;
        }

        name = n;
    }

    void setYear(string y){
        //validate input for empty string
        if(y.size() == 0){
            cout << "Build year cannot be empty!";
            cout << " Enter again: ";
            cin >> y;
        }

        //validate again for year of construction
        int yr = atoi(y.c_str());

        while(yr < 1700){
            cout << "Build year cannot be less";
            cout << " than 1700! Enter again: ";
            //read the string again
            cin >> y;
            //convert it to integer to
            //continue validation
            yr = atoi(y.c_str());
        }

        //after validation, set the value
        //to the member variable
        year = y;
    }

    //virtual print() function
    virtual void print() const{
        cout << "Name: " << name << endl;
        cout << "Build year: " << year << endl;
    }
};

#endif

