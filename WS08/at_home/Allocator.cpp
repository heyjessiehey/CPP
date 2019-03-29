//  Name        : Jessie Gayeon Ko
//  Student ID  : 040 704 124
//  Email       : gko4@myseneca.ca
//  Section     : OPP244SGG
//  Date        : Mar 27 2018
//  Virtual Functions

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//
    const double interest = 0.05;
    const double transaction = 0.5;
    const double monthly = 2;

	// TODO: Allocator function
	//
    iAccount* CreateAccount(const char* type, double bal){
        iAccount* ptr = nullptr;
        
        if(type[0] == 'S')
            ptr = new SavingsAccount(bal, interest);
        else if(type[0] == 'C')
            ptr = new ChequingAccount(bal, transaction, monthly);
        
        return ptr;
    }

}

/*
 receives the address of a C-style string that identifies the type of account to be created 
 
 
 and the initial balance in the account and returns its address to the calling function. 
 
 If the initial character of the string is 'S', this function creates a savings account in dynamic memory.
 
 If the string does not identify a type that is available, this function returns nullptr.
*/
