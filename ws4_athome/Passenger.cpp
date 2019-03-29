// TODO: add file header comments here
// Workshop 4
// Passenger.cpp
// Name: (Jessie) Gayeon Ko
// Section: OPP244SGG
// Student ID: 040704124
// Email: gko4@myseneca.ca
// Date: Feb 16 2018

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

// TODO: continue your namespace here
namespace sict
{
    // TODO: implement the default constructor here
    Passenger::Passenger()
    {
        m_passengerName[0] = '\0';
        m_destination[0] = '\0';
        m_year = 0;
        m_month = 0;
        m_day = 0;
    }

    // TODO: implement the constructor with 2 parameters here
    Passenger::Passenger(const char* name, const char* destination)
    {
        /*m_passengerName[0] = '\0';
        m_destination[0] = '\0';
        m_year = 0;
        m_month = 0;
        m_day = 0;*/

        if (name == nullptr || name[0] == '\0' || destination == nullptr || destination[0] =='\0')
            *this = Passenger();
        else
        {
            strncpy(m_passengerName, name, max_name_length + 1);
            m_passengerName[max_name_length] = '\0';
            strncpy(m_destination, destination, max_name_length + 1);
            m_destination[max_name_length] = '\0';
            m_year = 2017;
            m_month = 7;
            m_day = 1;
        }
    }

    Passenger::Passenger(const char* name, const char* destination, int yr, int mon, int day)
    {
        /*m_passengerName[0] = '\0';
        m_destination[0] = '\0';
        m_year = 0;
        m_month = 0;
        m_day = 0;*/

        if (name == nullptr || name[0] == '\0' || destination == nullptr || destination[0] == '\0' ||
            yr > 2020 || yr < 2017 || mon < 1 || mon > 12 || day < 1 || day > 31)
            *this = Passenger();
        else
        {
            strncpy(m_passengerName, name, max_name_length + 1);
            m_passengerName[max_name_length] = '\0';
            strncpy(m_destination, destination, max_name_length + 1);
            m_destination[max_name_length] = '\0';
            m_year = yr;
            m_month = mon;
            m_day = day;
        }
    }

    const char* Passenger::name() const
    {
        return m_passengerName;
    }

    bool Passenger::canTravelWith(const Passenger& passenger) const
    {
        bool together;
        if (m_year == passenger.m_year && m_month == passenger.m_month && m_day == passenger.m_day && strcmp(m_destination, passenger.m_destination) == 0)
            together = true;
        else
            together = false;

        return together;
    }

    // TODO: implement isEmpty query here
    bool Passenger::isEmpty() const
    {
        return m_passengerName[0] == '\0';
    }

    // TODO: implement display query here
    void Passenger::display() const
    {
        if (isEmpty() == true)
            cout << "No passenger!" << endl;
        else
        {
            cout << m_passengerName << " - " << m_destination << " on " << m_year << "/";
            cout.width(2);
            cout.fill('0');
            //cout.setf(ios::right);
            cout << m_month << "/" << m_day << endl;
            //cout.unsetf(ios::right);
        }
    }
}
