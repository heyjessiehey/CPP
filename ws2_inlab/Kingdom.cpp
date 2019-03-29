/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
//
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Jan 30 2018
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
    void display(const Kingdom& kingdom)
    {
        cout << kingdom.m_name << ", " << "population " << kingdom.m_population << endl;
    }
}
