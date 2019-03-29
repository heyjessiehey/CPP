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


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

using namespace std;

// TODO: the sict namespace
namespace sict {

// TODO:definition for display(...)
    void display(const Kingdom& akingdom)
    {
        cout << akingdom.m_name << ", " << "population " << akingdom.m_population << endl;
    }

// overload sict::display()
    void display(const Kingdom akingdom[], int num)
    {
        int total = 0;
        cout << "------------------------------\n"
             << "Kingdoms are\n"
             << "------------------------------\n";
        for(int i=0; i<num; i++)
        {
            cout << i + 1 << ". " << akingdom[i].m_name << ", "
                 << "population " << akingdom[i].m_population << endl;

            total += akingdom[i].m_population;
        }
        cout << "------------------------------\n"
             << "Total population of all Kingdoms: " << total << endl
             << "------------------------------\n";
    }
}
