/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
//
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Feb 4 2018
//    
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace
namespace sict {
    const int KINGDOM_NAME = 32;
// TODO: define the structure Kingdom in the sict namespace
    struct Kingdom{
        char m_name[KINGDOM_NAME];
        int m_population;
    };

// TODO: declare the function display(...),
//         also in the sict namespace
    void display(const Kingdom& akingdom);
    void display(const Kingdom akingdom[], int num); // overload sict::display()
}
#endif
