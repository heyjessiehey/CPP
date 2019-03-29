//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Feb 11 2018

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "CRA_Account.h"

using namespace std;

namespace sict
{
    void CRA_Account::set(const char* fname, const char* gname, int sin)
    {
        // when sin is invalid
        m_familyName[0] = '\0';
        m_givenName[0] = '\0';
        m_sin = 0;

        // first, check sin is valid in range and family and given names are not empty
        int sin2 = sin;
        if (sin2 >= min_sin && sin2 <= max_sin && fname[0] != '\0' && gname[0] != '\0')
        {
            int sum = 0;
            for(int i=0; i<5 ; i++) // second, check sin is valid the following rule
            {
                int a = sin2 %100; // extract last two digits
                int even = a /10 * 2; // extract even number and multiply * 2
                sum += (a % 10) + (even/10) + (even%10); // extract odd number and extract each even number
                sin2 /= 100; // extract left sin number to loop again
            }

            if(sum % 10 == 0) // when sin is satisfied the rule
            {
                strncpy(m_familyName, fname, max_name_length +1);
                m_familyName[max_name_length] = '\0';
                strncpy(m_givenName, gname, max_name_length +1);
                m_givenName[max_name_length] ='\0';
                m_sin = sin;
            }
        }

        // initializes rest of data members that is stored to 0
        for(int i=0; i<max_yrs; i++)
        {
            m_returnYear[i] = 0;
            m_balance[i] = 0;
        }
        m_years =0;
    }

    void CRA_Account::set(int reyear, double bal)
    {
        if (!isEmpty() && m_years < max_yrs)
        {
            m_returnYear[m_years] = reyear;
            m_balance[m_years] = bal;
            m_years++;
        }
    }

    void CRA_Account::display() const
    {
        if (!isEmpty())
        {
            cout << "Family Name: " << m_familyName << endl;
            cout << "Given Name : " << m_givenName << endl;
            cout << "CRA Account: " << m_sin << endl;

            for (int i = 0; i < max_yrs; i++)
            {
                cout << "Year (" << m_returnYear[i] << ")";
                cout << fixed << setprecision(2);


                if (m_balance[i] > 2.00)
                {
                    cout << " balance owing: " << m_balance[i] << endl;
                }
                else if (m_balance[i] < -2.00)
                {
                    cout << " refund due: " << -m_balance[i] << endl;
                } else
                {
                    cout << " No balance owing or refund due!" << endl;
                }
            }
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
