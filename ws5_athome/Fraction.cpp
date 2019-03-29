//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Feb 25 2018

// TODO: insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;
// TODO: continue the namespace
namespace sict {
    // TODO: implement the
    Fraction::Fraction(){
        this -> m_num = 0;
        this -> m_denom = 0;
    }
    // TODO: implement the two-argument constructor
    Fraction::Fraction(int num, int denom) {
        if (num < 0 || denom < 0){
            *this = Fraction();
        }else{
            m_num = num;
            m_denom = denom;
            reduce();
        }
    }
    // TODO: implement the max query
    int Fraction::max() const{
        return (m_num > m_denom ? m_num : m_denom);
    }
    // TODO: implement the min query
    int Fraction::min() const{
        return (m_num < m_denom ? m_num : m_denom);
    }
    // gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const{
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce(){
        int g_c_d = gcd();
        m_num /= g_c_d;
        m_denom /= g_c_d;
    }
    // TODO: implement the display query
    void Fraction::display() const{
        if(isEmpty()){
            cout << "no fraction stored";
        }else if ((m_num/m_denom) < 1){
            cout << m_num << "/" << m_denom;
        }else{
            cout << m_num;
        }

    }
    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const{
        bool result = false;
        if (m_num == 0 && m_denom == 0) {
            result = true;
        }
        return result;
    }
    // TODO: implement the + operator
    Fraction Fraction::operator+(const Fraction& rhs) const{
        Fraction result;
        if(!isEmpty() && !rhs.isEmpty()){
            result.m_num = (m_num * rhs.m_denom) + (m_denom * rhs.m_num);
            result.m_denom = m_denom * rhs.m_denom;
            result.reduce();
        }
        return result;
    }

    Fraction Fraction::operator*(const Fraction& rhs) const{
        Fraction result;
        if(!isEmpty() && !rhs.isEmpty()){
            result.m_num = m_num * rhs.m_num;
            result.m_denom= m_denom * rhs.m_denom;
            result.reduce();
        }
        return result;
    }

    bool Fraction::operator==(const Fraction& rhs) const{
        bool result = false;
        if(!isEmpty() && !rhs.isEmpty()) {
            if(m_num == rhs.m_num && m_denom == rhs.m_denom) {
                result = true;
            }
        }
        return result;
    }

    bool Fraction::operator!=(const Fraction& rhs) const{
        bool result = false;
        if(!isEmpty() && !rhs.isEmpty()){
            if(m_num != rhs.m_num && m_denom != rhs.m_denom){
                result = true;
            }
        }
        return result;
    }

    Fraction& Fraction::operator+=(const Fraction& rhs){
        if(!isEmpty() && !rhs.isEmpty()) {
            *this = *this + rhs;
            reduce();
        }
    } return *this;
}
