//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Feb 6 2018

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict
{
    void CRA_Account::set(const char* fname, const char* gname, int sin)
    {
        if (sin >= min_sin && sin <= max_sin)
        {
            strncpy(m_familyName, fname, max_name_length + 1);
            m_familyName[max_name_length] = '\0';
            strncpy(m_givenName, gname, max_name_length + 1);
            m_givenName[max_name_length] = '\0';
            m_sin = sin;
        }
        else
        {
            m_familyName[0] = '\0';
            m_givenName[0] = '\0';
            m_sin = 0;
        }
    }

    void CRA_Account::display() const
    {
        if (!isEmpty())
        {
            cout << "Family Name: " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;
        }
        else
        {
            cout << "Account object is empty!" << endl;
        }
    }
    
    bool CRA_Account::isEmpty() const
    {
        return m_sin == 0;
    }
}
