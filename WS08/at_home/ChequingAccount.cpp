// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

//  Name        : Jessie Gayeon Ko
//  Student ID  : 040 704 124
//  Email       : gko4@myseneca.ca
//  Section     : OPP244SGG
//  Date        : Mar 27 2018
//  Virtual Functions

#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
    ChequingAccount::ChequingAccount(double bal, double tranFee, double monFee)
    : Account(bal){
        m_transactionFee = tranFee > 0 ? tranFee : 0; // conditional ternary operator
        m_monthEndFee = monFee > 0 ? monFee : 0;
    }
    

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
    bool ChequingAccount::credit(double amt){
        if (Account::credit(amt)){ // shadowing
            if(Account::debit(m_transactionFee)) // shadowing
                return true;
        }
        return false;
    }



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
    bool ChequingAccount::debit(double amt){
        if (Account::debit(amt)){ // shadowing
            if(Account::debit(m_transactionFee)) // shadowing
                return true;
        }
        return false;
    }



	// monthEnd debits month end fee
	//
    void ChequingAccount::monthEnd(){
        Account::debit(m_monthEndFee + m_transactionFee); // shadowing
       // Account::debit(m_transactionFee);
    }



	// display inserts account information into ostream os
	//

    void ChequingAccount::display(ostream& os) const{
        os.setf(ios::fixed);
        os.precision(2);
        os << "Account type: Chequing" << endl;
        os << "Balance: $" << balance() << endl;
        os << "Per Transaction Fee: " << m_transactionFee << endl;
        os << "Monthly Fee: " << m_monthEndFee << endl;
    }


}
