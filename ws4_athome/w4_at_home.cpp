// Workshop 4 - Constructors - Test Main
// w4_at_home.cpp
// Chris Szalwinski
// 9/23/2017
//
// Name: (Jessie) Gayeon Ko
// Section: OPP244SGG
// Student ID: 040704124
// Email: gko4@myseneca.ca
// Date: Feb 16 2018

#include <iostream>
#include "Passenger.h"

using namespace std;
using namespace sict;

int main()
{
    Passenger travellers[] = {
            Passenger(nullptr, "Toronto", 2018, 4, 20),
            Passenger("", "Toronto", 2018, 4, 20),
            Passenger("John Smith", nullptr, 2018, 4, 20),
            Passenger("John Smith", "", 2018, 4, 20),
            Passenger("John Smith", "Toronto", 2018, 4, 20), // valid
            Passenger("John Smith", "Toronto", 2028, 4, 20),
            Passenger("John Smith", "Toronto", 2014, 4, 20),
            Passenger("John Smith", "Toronto", 2020, 12, 31), // valid
            Passenger("John Smith", "Toronto", 2018, 40, 20),
            Passenger("John Smith", "Toronto", 2018, 0, 20),
            Passenger("John Smith", "Toronto", 2017, 1, 1), // valid
            Passenger("John Smith", "Toronto", 2018, 4, 0),
            Passenger("John Smith", "Toronto", 2018, 4, 32),
            Passenger(nullptr, nullptr, 0, 0, 0),
            Passenger()
    };
    cout << "----------------------------------------" << endl;
    cout << "Testing the validation logic" << endl;
    cout << "(only passengers 5, 8 and 11 should be valid)" << endl;
    cout << "----------------------------------------" << endl;
    for (unsigned int i = 0; i < 15; ++i)
    {
        cout << "Passenger " << i + 1 << ": "
             << (travellers[i].isEmpty() ? "not valid" : "valid") << endl;
    }
    cout << "----------------------------------------" << endl << endl;

    Passenger david("David", "Toronto", 2018, 4, 20);
    Passenger friends[] = {
            Passenger("Vanessa", "Toronto", 2018, 4, 20),
            Passenger("John", "Toronto", 2018, 4, 20),
            Passenger("Alice", "Toronto", 2018, 4, 20),
            Passenger("Bob", "Paris", 2018, 1, 20),
            Passenger("Jennifer", "Toronto", 2018, 4, 20),
            Passenger("Mike", "Toronto", 2018, 4, 20),
            Passenger("Sarah", "Toronto", 2018, 4, 20)
    };

    cout << "----------------------------------------" << endl;
    cout << "Testing Passenger::display(...)" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 7; ++i)
        friends[i].display();
    cout << "----------------------------------------" << endl << endl;

    cout << "----------------------------------------" << endl;
    cout << "Testing Passenger::canTravelWith(...)" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 7; ++i) {
        if (david.canTravelWith(friends[i]))
            cout << david.name() << " can travel with " << friends[i].name() << endl;
    }
    cout << "----------------------------------------" << endl << endl;

    return 0;
}

/*
----------------------------------------
Testing the validation logic
(only passengers 5, 8 and 11 should be valid)
----------------------------------------
Passenger 1: not valid
Passenger 2: not valid
Passenger 3: not valid
Passenger 4: not valid
Passenger 5: valid
Passenger 6: not valid
Passenger 7: not valid
Passenger 8: valid
Passenger 9: not valid
Passenger 10: not valid
Passenger 11: valid
Passenger 12: not valid
Passenger 13: not valid
Passenger 14: not valid
Passenger 15: not valid
----------------------------------------

----------------------------------------
Testing Passenger::display(...)
----------------------------------------
Vanessa - Toronto on 2018/04/20
John - Toronto on 2018/04/20
Alice - Toronto on 2018/04/20
Bob - Paris on 2018/01/20
Jennifer - Toronto on 2018/04/20
Mike - Toronto on 2018/04/20
Sarah - Toronto on 2018/04/20
----------------------------------------

----------------------------------------
Testing Passenger::canTravelWith(...)
----------------------------------------
David can travel with Vanessa
David can travel with John
David can travel with Alice
David can travel with Jennifer
David can travel with Mike
David can travel with Sarah
----------------------------------------
 */