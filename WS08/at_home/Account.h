//  Name        : Jessie Gayeon Ko
//  Student ID  : 040 704 124
//  Email       : gko4@myseneca.ca
//  Section     : OPP244SGG
//  Date        : Mar 27 2018
//  Virtual Functions

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
    class Account : public iAccount{ // An absract base class 
        
        double m_balance;

	protected:
        double balance() const {return m_balance;}

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
        Account(double bal){m_balance = bal >= 0 ? bal : 0;} // conditional ternary operator 

		// TODO: credit adds +ve amount to the balance 
        virtual bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
        virtual bool debit(double);
        
	};
    iAccount* CreateAccount(const char*, double);
}
#endif
