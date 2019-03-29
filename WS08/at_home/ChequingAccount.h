//  Name        : Jessie Gayeon Ko
//  Student ID  : 040 704 124
//  Email       : gko4@myseneca.ca
//  Section     : OPP244SGG
//  Date        : Mar 27 2018
//  Virtual Functions

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include <iostream>
#include "Account.h"

namespace sict {
    class ChequingAccount :public Account { // An concrete class
        
        double m_transactionFee;
        double m_monthEndFee;

    public:
        // TODO: constructor initializes account balance and transaction fee
        ChequingAccount(double, double, double);

        // TODDO: credit adds +ve amount to the balance
       virtual bool credit(double);

        // TODO: debit subtracts a +ve amount from the balance
       virtual bool debit(double);

        // TODO: month end
       virtual void monthEnd();

        // TODO: display inserts the account information into an ostream
       virtual void display(std::ostream&) const;

	};
}
#endif
