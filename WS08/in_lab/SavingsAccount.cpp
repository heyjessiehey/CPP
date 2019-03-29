//  Name        : Jessie Gayeon Ko
//  Student ID  : 040 704 124
//  Email       : gko4@myseneca.ca
//  Section     : OPP244SGG
//  Date        : Mar 27 2018
//  Virtual Functions

#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {
   
    void SavingsAccount::monthEnd(){
        double interest = balance() * m_interest;
        credit(interest);
    }
    
    void SavingsAccount::display(ostream& os) const{
        os.setf(ios::fixed);
        os.precision(2);
        os << "Account type: Savings" << endl;
        os << "Balance: $" << balance() << endl;
        os << "Interest Rate (%): " << m_interest * 100 << endl;
    }
}


/*
 "	void monthEnd() - this modifier calculates the interest earned on the current balance and credits the account with that interest.
 
 
 "	void display(std::ostream&) - receives a reference to an ostream object and inserts the following output on separate lines to the object. The values marked in red are fixed format with 2 decimal places and no fixed field width:
 o	Account type: Savings
 o	Balance: $xxxx.xx
 o	Interest Rate (%): x.xx

 */
