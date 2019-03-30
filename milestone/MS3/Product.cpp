//
//  Product.cpp
//  ms3
//
//  Created by Gayeon Ko on 2018-03-31.
//  Copyright © 2018 (Jessie) Gayeon Ko. All rights reserved.
//
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Milesstone3

#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"
#define COMMA ','


using namespace std;

namespace AMA {
    
    //protected member functions
    void Product::name(const char* prodName){
        if(prodName != nullptr){
            m_productName = new char[strlen(prodName) +1];
            strcpy(m_productName, prodName);
        }else{
            delete [] m_productName;
        }
    }
    
    const char* Product::name() const{
        return m_productName != nullptr ? m_productName : nullptr;
    }
    
    double Product::cost() const{
        double cost = m_price;
        if(m_taxable)
            cost = m_price + (m_price*TAX);
        return cost;
    }
    
    void Product::message(const char* errMsg){
        //This function receives the address of a C-style null-terminated string holding an error message and stores that message in the ErrorState object.
        m_error.message(errMsg);
    }
    
    bool Product::isClear() const{
        return m_error.isClear();
    }
    const char* Product::sku() const{
        return m_stockKeepingUnit;
    }
    
    const char* Product::unit() const{
        return m_unitDesc;
    }
    
    bool Product::taxed() const{
        return m_taxable;
    }
    
    double Product::price() const{
        return m_price;
    }
    
    
    //public member functions
    Product::Product(char prodType){
        if(prodType != '\0')
            m_productType = prodType;
        else
            m_productType = '\0';
        
        m_stockKeepingUnit[0] = '\0';
        m_productName = nullptr;
        m_price = 0;
        m_taxable = true;
        m_unitDesc[0] = '\0';
        m_neededUnits = 0;
        m_currentUnits = 0;
    
    }
    
    Product::Product(const char* sku, const char* prodName, const char* unit, int no, bool taxable, double price, int needed){
        
        strncpy(m_stockKeepingUnit, sku, MAX_SKU+1);
        //m_stockKeepingUnit[MAX_SKU] = '\0';
        name(prodName);
        strncpy(m_unitDesc, unit, MAX_UNIT+1);
        //m_unitDesc[MAX_UNIT] = '\0';
        m_currentUnits = no;
        m_taxable = taxable;
        m_price = price;
        m_neededUnits = needed;
    }

    Product::Product(const Product& obj){
        m_productName = nullptr;
        *this = obj;
    }
    
    Product::~Product(){
        delete [] m_productName;
        m_error.clear();
    }


    double Product::total_cost() const{
        return m_currentUnits*cost();
    }
    
    void Product::quantity(int product){
        m_currentUnits = product;
    }
    
    bool Product::isEmpty() const{
        return m_productType == '\0' && m_stockKeepingUnit[0] == '\0' && m_productName == nullptr &&
                m_price == 0 && m_unitDesc[0] == '\0' && m_neededUnits == 0 && m_currentUnits == 0;
    }
    
    int Product::qtyNeeded() const{
        return m_neededUnits;
    }
    
    int Product::quantity() const{
        return m_currentUnits;
    }



    Product& Product::operator=(const Product& obj){
        if(this != &obj){
            delete[] m_productName;
            name(obj.m_productName);
            m_productType = obj.m_productType;
            strncpy(m_stockKeepingUnit, obj.m_stockKeepingUnit, MAX_SKU+1);
            //m_stockKeepingUnit[MAX_SKU] = '\0';
            strncpy(m_unitDesc, obj.m_unitDesc, MAX_UNIT);
            //m_unitDesc[MAX_UNIT] = '\0';
            m_currentUnits = obj.m_currentUnits;
            m_neededUnits = obj.m_neededUnits;
            m_price = obj.m_price;
            m_taxable = obj.m_taxable;
            m_error.message(obj.m_error.message());
        }
        return *this;
    }

    bool Product::operator==(const char* str) const{
        return strcmp(m_stockKeepingUnit, str) == 0;
    }

    bool Product::operator>(const char* str) const{
        return strcmp(m_stockKeepingUnit, str) > 0;
    }
    
    bool Product::operator>(const Product& obj) const{
        return strcmp(m_productName, obj.name()) > 0;
    }
    
    int Product::operator+=(int unitAdded){
        return m_currentUnits += unitAdded;
    }


    std::ostream& Product::write(std::ostream& os, bool linear) const{
        if(linear){
            //s << "sku - ";
            os.width(MAX_SKU);
            os.setf(ios::left);
            os << m_stockKeepingUnit << '|';
            //os << "name - ";
            os.width(20);
            os << m_productName << '|';
            os.unsetf(ios::left);
            //os << "cost - ";
            os.width(7);
            os.setf(ios::fixed);
            os.precision(2);
            os << cost() << '|';
            //os.unsetf(ios::fixed);
            //os << "quantity - ";
            os.width(4);
            os << m_currentUnits << '|';
            //os << "unit - ";
            os.width(10);
            os.setf(ios::left);
            os << m_unitDesc << '|';
            os.unsetf(ios::left);
            //os << "quantity needed - ";
            os.width(4);
            os << m_neededUnits << '|';
        }else{
            os << "Sku: " << m_stockKeepingUnit << '|' << endl
               << "name: " << m_productName << '|' << endl
               << "price: " << m_price << '|' << endl;
            if(m_taxable)
                os << "Price after tax: " << cost() << '|' <<endl;
            else
                os << "M/A" << '|' <<endl;
            os << "Quantity on hand: " << m_currentUnits << '|' << endl
               << "Quantity needed: " << m_neededUnits << '|' << endl;
        }
        return os;
    }

    std::istream& Product::read(std::istream& is){
        char sku[MAX_SKU+1];
        char* prodName;
        char unit[MAX_UNIT+1];
        char tax[1];
        double price;
        int qtyHand;
        int qtyNeeded;

        prodName = new char[MAX_USER+1];

        std::cout << " Sku: ";
        is >> sku;

        std::cout << " Name (no spaces): ";
        is >> prodName;

        std::cout << " Unit: ";
        is >> unit;

        std::cout << " Taxed? (y/n): ";
        is >> tax[0];
        if(tax[0] != 'y' && tax[0] != 'Y' && tax[0] != 'n' && tax[0] != 'N'){
            is.setstate(std::ios::failbit);
            m_error.message("Only (Y)es or (N)o are acceptable");
        }

        std::cout << " Price: ";
        is >> price;
        if(is.fail()){
            is.setstate(std::ios::failbit);
            m_error.message("Invalid Price Entry");
        }

        std::cout << " Quantity on hand: ";
        is >> qtyHand;
        if(is.fail()){
            is.setstate(std::ios::failbit);
            m_error.message("Invalid Quantity Entry");
        }

        std::cout << " Quantity needed: ";
        is >> qtyNeeded;
        if(is.fail()){
            is.setstate(std::ios::failbit);
            m_error.message("Invalid Quantity Needed Entry");
        }

        if(m_error.isClear()){
            strncpy(m_stockKeepingUnit, sku, MAX_SKU+1);
            //m_stockKeepingUnit[MAX_SKU] = '\0';
            name(prodName);
            strncpy(m_unitDesc, unit, MAX_UNIT+1);
            //m_unitDesc[MAX_UNIT] = '\0';
            m_taxable = tax[0] == 'y' || tax[0] == 'Y';
            m_price = price;
            m_currentUnits = qtyHand;
            m_neededUnits =  qtyNeeded;
        }

        delete [] prodName;
        return is;
    }
    std::fstream& Product::store(std::fstream& file, bool newLine) const{
        file << m_stockKeepingUnit << COMMA << m_currentUnits << COMMA << m_taxable << COMMA << m_price << COMMA
             << m_productName << COMMA << m_neededUnits << COMMA << m_unitDesc << COMMA;
        if(newLine)
            file << endl;
        return file;
    }

    std::fstream& Product::load(std::fstream& file){
        Product temp;
        temp.m_productName = new char[MAX_USER +1];
        if(file.is_open()){
            file << temp.m_stockKeepingUnit << temp.m_currentUnits << temp.m_taxable << temp.m_price
                 << temp.m_productName << temp.m_neededUnits << temp.m_unitDesc << temp.m_unitDesc;
            *this = temp;
        }
        delete [] temp.m_productName;
        return file;
    }

    //helper functions
    std::ostream& operator<<(std::ostream& os, const Product& obj){
        return obj.write(os, true);
    }
    
    std::istream& operator>>(std::istream& is, Product& obj){
        obj.read(is);
        return is;
    }
    
    double operator+=(double& cost, const Product& obj){
        return cost + obj.total_cost();
    }
}
