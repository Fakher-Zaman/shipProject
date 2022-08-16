//contents of main.cpp

#include <iostream>
#include "Ship.h"
#include "Ship 2.h"
#include "Ship 3.h"

using namespace std;

int main()
{
    //create array of Ship pointers, and dynamically
    //allocate the objects
    cout << "Now creating array of Ship pointers to\n";
    cout << "reference the Ship, CruiseShip and CargoShip\n";
    cout << "objects...\n";

    //use initialization list, dynamically allocating
    //each pointer to objects with default values
    Ship *ships[3] = {
                      new Ship(),
                      new CruiseShip(),
                      new CargoShip()
                      };
    cout << "Done!\n";

    //use the print function to print the data
    //for each ship
    cout << "\nNow printing the data for each ship...\n";
    for(int i = 0; i < 3; i++){
        ships[i]->print();
        cout << endl;
    }

    //now use mutator functions to store new data
    //into the objects
    cout << "Now setting the Ship's name and construction year...\n";
    ships[0]->setName("HMS Slader");
    ships[0]->setYear("2010");
    cout << "Done!\n";

    //we need a pointer to the derived class to access
    //the functions that only exist in the derived class
    //don't forget to use static_cast<DerivedClassPointer>
    //otherwise, a derived class pointer cannot
    //point to the same location as a base class pointer
    CruiseShip *csPoint = static_cast<CruiseShip*>(ships[1]);
    cout << "\nNow setting the CruiseShip's name and occupancy...\n";
    csPoint->setName("HMS Titanic");
    csPoint->setMaxPassengers(2000);
    cout << "Done!\n";

    //the same applies for this derived class
    CargoShip *cgPoint = static_cast<CargoShip*>(ships[2]);
    cout << "\nNow setting the CargoShip's name and capacity...\n";
    cgPoint->setName("HMS CargoZoom");
    cgPoint->setMaxCapacity(150000);
    cout << "Done!\n";

    //display data again
    //now using the base class pointers
    cout << "\nNow printing the data for each ship again...\n";
    for(int i = 0; i < 3; i++){
        ships[i]->print();
        cout << endl;
    }

    //return 0 to mark successful termination
    return 0;
}

