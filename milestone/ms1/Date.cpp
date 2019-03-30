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
//Milesstone1

#include <iostream>
#include "Date.h"
using namespace std;

namespace AMA {

  // number of days in month mon_ and year year_
  //
    int Date::mdays(int mon, int year)const{
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    
    void Date::errCode(int errorcode){
        m_error = errorcode;
    }
    
    void Date::set(int _yr, int _mon, int _day, int _err){
        m_year = _yr;
        m_month = _mon;
        m_day = _day;
        errCode(_err);
        if(_err == NO_ERROR)
            m_comparator = _yr*372 + _mon*12 + _day;
        else
            m_comparator = 0;
        
    }
    void Date::check(int _y, int _m, int _d){
        
        if(_y > max_year || _y < min_year)
            set(0, 0, 0, YEAR_ERROR);
        else if(_m > 12 || _m < 1)
            set(0, 0, 0, MON_ERROR);
        else if(_d > mdays(_m, _y ) || _d < 1)
            set(0, 0, 0, DAY_ERROR);
        else
            set(_y, _m, _d, NO_ERROR);
    }

    Date::Date(){
        set(0, 0, 0, NO_ERROR);
    }
    
    Date::Date(int yr, int mon, int day){
        if(yr <= max_year && yr >= min_year){
            m_year = yr;
            errCode(NO_ERROR);
            if(mon < 13 && mon >0){
                m_month = mon;
            }else
                m_month = 0;
            if(day > 0 && day <= mdays(mon, day)){
                m_day = day;
            }else
                m_day = 0;
            if(m_error == NO_ERROR){
                m_comparator = yr*372 + mon*12 + day;
            }
        }else
            check(yr, mon, day);
        
    }
    
    // Copy Assignment Operator
    
    bool Date::operator==(const Date& rhs) const{
        if(isEmpty() || rhs.isEmpty())
            return false;
        
       if(m_comparator == rhs.m_comparator){
            return true;
        }
        return false;
    }
    
    bool Date::operator!=(const Date& rhs) const{
        if(isEmpty() || rhs.isEmpty())
            return false;
        
        if(m_comparator != rhs.m_comparator)
            return true;
        
        return false;
    }
    
    bool Date::operator<(const Date& rhs) const{
        if(isEmpty() || rhs.isEmpty())
            return false;
        
        if(m_comparator < rhs.m_comparator){
            return true;
        }
        return false;
        
    }
    
    bool Date::operator>(const Date& rhs) const{
        if(isEmpty() || rhs.isEmpty())
            return false;
        
        if(m_comparator > rhs.m_comparator){
            return true;
        }
        return false;
    }
    
    bool Date::operator<=(const Date& rhs) const{
        if(isEmpty() || rhs.isEmpty())
            return false;
        
        if(m_comparator <= rhs.m_comparator){
            return true;
        }
        return false;
    }
    
    bool Date::operator>=(const Date& rhs) const{
        if(isEmpty() || rhs.isEmpty())
            return false;
        
        if(m_comparator >= rhs.m_comparator){
            return true;
        }
        return false;
    }
    
    // Queries
    bool Date::isEmpty() const{
        return m_year == 0 && m_month == 0 && m_day == 0;
    }
    
    int Date::errCode() const{
        return m_error;
    }
    
    bool Date::bad() const{
        if(m_error == NO_ERROR)
            return true;
        return false;
    }
    
    // Standard I/O Operators - modifier
    
    istream& Date::read(istream& istr){ // cin >>
        int y, m, d;
    
        istr >> y;
        istr.ignore();
        if(istr.fail()){
            set(0, 0, 0, CIN_FAILED);
            return istr;
        }
      
        istr >> m;
        istr.ignore();
        if(istr.fail()){
            set(0, 0, 0, CIN_FAILED);
            return istr;
        }
        istr >> d;
        
        check(y, m, d);
        
        return istr;
    }
    
    ostream& Date::write(ostream& ostr) const{ // cout <<
        ostr << m_year << "/";
        char old = cout.fill('0');
        ostr.width(2);
        ostr << m_month << "/";
        ostr.width(2);
        ostr << m_day;
        ostr.fill(old);
        return ostr;
    }
    
    //helper functions
    
    istream& operator>>(istream& is, Date& _Date){
        _Date.read(is);
        return is;
    }
    
    ostream& operator<<(ostream& os, const Date& _Date){
        _Date.write(os);
        return os;
    }



}
