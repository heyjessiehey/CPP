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
        double interest = Account::balance() * m_interest;
        Account::credit(interest);
    }
    
    void SavingsAccount::display(ostream& os) const{
        os.setf(ios::fixed);
        os.precision(2);
        os << "Account type: Savings" << endl;
        os << "Balance: $" << Account::balance() << endl;
        os << "Interest Rate (%): " << m_interest * 100 << endl;
    }
}



