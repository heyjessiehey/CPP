// TODO: add file header comments here
// Workshop 4
// Passenger.h
// Name: (Jessie) Gayeon Ko
// Section: OPP244SGG
// Student ID: 040704124
// Email: gko4@myseneca.ca
// Date: Feb 16 2018

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: declare your namespace here
namespace sict
{
    const int max_name_length = 31;
    // TODO: define the Passenger class here
    class Passenger
    {
        char m_passengerName[max_name_length + 1];
        char m_destination[max_name_length + 1];
        int m_year;
        int m_month;
        int m_day;

    public:
        Passenger();
        Passenger(const char* name, const char* destination);
        Passenger(const char* name, const char* destination, int yr, int mon, int day);
        const char* name() const;
        bool canTravelWith(const Passenger& passenger) const;
        void display() const;
        bool isEmpty() const;
    };

}

#endif
