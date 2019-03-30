//
//  Product.h
//  ms3
//
//  Created by Gayeon Ko on 2018-03-31.
//  Copyright © 2018 (Jessie) Gayeon Ko. All rights reserved.
//
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Milestone3

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include <fstream>
#include "ErrorState.h"


namespace AMA {
    
    const char MAX_SKU = 7;
    const char MAX_UNIT = 10;
    const char MAX_USER = 75;
    const double TAX = 0.13;

    
    const char max_sku_length = MAX_SKU;
    const char max_unit_length = MAX_UNIT;
    const char max_name_length = MAX_USER;
    
    class Product{
        
        char m_productType;
        char m_stockKeepingUnit[MAX_SKU +1];
        char m_unitDesc[MAX_UNIT +1];
        char* m_productName;
        int m_currentUnits;
        int m_neededUnits;
        double m_price;
        bool m_taxable;
        ErrorState m_error;
        
    protected:
        
        void name(const char* prodName);
        const char* name() const;
        double cost() const;
        void message(const char* errMsg);
        bool isClear() const;
        
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double price() const;
        
    public:
        
        Product(char prodType = 'N');
        Product(const char* sku, const char* prodName, const char* unit, int no=0, bool taxable=true, double price=0, int needed=0);
        Product(const Product&);
        Product& operator=(const Product& obj);
        ~Product();
        
        std::fstream& store(std::fstream& file, bool newLine=true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        bool operator>(const Product&) const;
        int operator+=(int);
    };
    
    std::ostream& operator<<(std::ostream&, const Product&);
    std::istream& operator>>(std::istream&, Product&);
    double operator+=(double&, const Product&);
}

#endif
