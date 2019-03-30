//
// Created by Gayeon Ko on 2018-04-12.
//
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Milestone5

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include "Date.h"
#include "Product.h"

namespace AMA {
    class Perishable : public Product{
        Date m_expiryDateforPerishable;

    public:
        Perishable() : Product('P') {m_error.clear();}
        virtual std::fstream& store(std::fstream& file, bool newLine=true) const;
        virtual std::fstream& load(std::fstream& file);
        virtual std::ostream& write(std::ostream& os, bool linear) const;
        virtual std::istream& read(std::istream& is);
        const Date& expiry() const;
    };
}

#endif //MS5_PERISHABLE_H
