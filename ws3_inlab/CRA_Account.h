//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Feb 6 2018

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict
{

    const int max_name_length = 40; 
    const int min_sin = 100000000;  
    const int max_sin = 999999999; 

    class CRA_Account
    {
        char m_familyName[max_name_length + 1];
        char m_givenName[max_name_length + 1];
        int  m_sin;
    public:
        void set(const char* fname, const char* gname, int sin);
        void display() const;
        bool isEmpty() const;
    };
}

#endif

