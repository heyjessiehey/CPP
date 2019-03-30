//
// Created by Gayeon Ko on 2018-04-12.
//
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Milestone5

#include <iostream>
#include <fstream>
#include "Perishable.h"

using namespace std;

namespace AMA{

    fstream& Perishable::store(fstream& file, bool newLine) const{
        Product::store(file, false);
        file << ',' << m_expiryDateforPerishable << endl;

        return file;
    }

    fstream& Perishable::load(fstream& file){
        Product::load(file);
        m_expiryDateforPerishable.read(file);
        file.ignore();

        return file;
    }

    ostream& Perishable::write(ostream& os, bool linear) const{
        Product::write(os, linear);

        if (isClear() && !isEmpty()){
            if (linear)
                m_expiryDateforPerishable.write(os);
            else {
                os << endl << " Expiry date: ";
                m_expiryDateforPerishable.write(os);
            }
        }
        return os;
    }

    istream& Perishable::read(istream& is){
        is.clear();
        Product::read(is);

        if (m_error.isClear()) {
            cout << " Expiry date (YYYY/MM/DD): ";
            m_expiryDateforPerishable.read(is);
        }
        if (m_expiryDateforPerishable.errCode() == CIN_FAILED){
            m_error.clear();
            m_error.message("Invalid Date Entry");
        }
        if (m_expiryDateforPerishable.errCode() == YEAR_ERROR){
            m_error.message("Invalid Year in Date Entry");
        }
        if (m_expiryDateforPerishable.errCode() == MON_ERROR){
            m_error.clear();
            m_error.message("Invalid Month in Date Entry");
        }
        if (m_expiryDateforPerishable.errCode() == DAY_ERROR){
            m_error.clear();
            m_error.message("Invalid Day in Date Entry");
        }
        if (m_expiryDateforPerishable.errCode()){
            is.setstate(ios::failbit);
        }
        if (m_expiryDateforPerishable.errCode() != CIN_FAILED && m_expiryDateforPerishable.errCode() != YEAR_ERROR
            && m_expiryDateforPerishable.errCode() != MON_ERROR && m_expiryDateforPerishable.errCode() != DAY_ERROR)
            m_error.clear();

        return is;
    }

    const Date& Perishable::expiry() const{
        return m_expiryDateforPerishable;
    }

}