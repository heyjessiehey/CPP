// TODO: add file header comments here
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Feb 13 2018

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
		//cout << "Passenger::Passenger()" << endl;
		m_passengerName[0] = '\0';
		m_destination[0] = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination)
	{
		//cout << "Passenger::Passenger(...)" << endl;
		if (name == nullptr || destination == nullptr || destination[0] == '\0')
			*this = Passenger();
		else
		{
			strncpy(m_passengerName, name, max_name_length + 1);
			m_passengerName[max_name_length] = '\0';
			strncpy(m_destination, destination, max_name_length + 1);
			m_destination[max_name_length] = '\0';
		}
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
			cout << m_passengerName << " - " << m_destination << endl;
		}

	}
}
