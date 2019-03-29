//  Name        : Jessie Gayeon Ko
//  Student ID  : 040 704 124
//  Email       : gko4@myseneca.ca
//  Section     : OPP244SGG
//  Date        : Mar 27 2018
//  Virtual Functions

#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {
    
    bool Account::credit(double amt){
        if(amt > 0){
            m_balance += amt;
            return true;
        }else
            return false;
    }
    
    bool Account::debit(double amt){
        if(amt > 0){
            m_balance -= amt;
            return true;
        }else
            return false;
    }
    
}
