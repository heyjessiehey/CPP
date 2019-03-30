// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Mar 15 2018
//Milestone5

#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

#define NO_ERROR   0  // No error - the date is valid
#define CIN_FAILED 1  // istream failed on information entry
#define YEAR_ERROR 2  // Year value is invalid
#define MON_ERROR  3  // Month value is invalid
#define DAY_ERROR  4  // Day value is invalid


namespace AMA {
    
    const int min_year = 2000;
    const int max_year = 2030;
    
    class Date {
        
        int m_year;
        int m_month;
        int m_day;
        int m_comparator;
        int m_error;
        
        int mdays(int , int)const; //number of days in month of year
        void errCode(int errorcode); //set the error state variable
        void set(int, int, int, int);
        void check(int, int, int);
        
        
  public:
        Date();
        Date(int, int, int);
        
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
       
        bool isEmpty() const;
        int errCode() const;
        bool bad() const;
        
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
  };

    std::istream& operator>>(std::istream& is, Date& _Date);
    std::ostream& operator<<(std::ostream& os, const Date& _Date);
    
}
#endif
