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
//Milestone5

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
        m_taxable = false;
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
    
    void Product::quantity(int qty){
        m_currentUnits = qty;
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

    bool Product::operator>(const iProduct& obj) const{
        return strcmp(m_productName, obj.name()) > 0;
    }
    
    bool Product::operator>(const Product& obj) const{
        return strcmp(m_productName, obj.name()) > 0;
    }
    
    int Product::operator+=(int unitAdded){
        return m_currentUnits += unitAdded;
    }


    ostream& Product::write(ostream& os, bool linear) const{
        if(!(m_error.isClear()))
            os << m_error.message();
        else if(linear){
            os.fill(' ');
            os.width(MAX_SKU);
            os.setf(ios::left);
            os << m_stockKeepingUnit << '|';

            os.width(20);
            os << m_productName << '|';
            os.unsetf(ios::left);

            os.width(7);
            os.setf(ios::fixed);
            os.precision(2);
            os << cost() << '|';

            os.width(4);
            os << m_currentUnits << '|';

            os.width(10);
            os.setf(ios::left);
            os << m_unitDesc << '|';
            os.unsetf(ios::left);

            os.width(4);
            os << m_neededUnits << '|';
        }else{
            os << " Sku: " << m_stockKeepingUnit << endl
               << " Name (no spaces): " << m_productName << endl
               << " Price: " << m_price << endl;
            if(m_taxable)
                os << " Price after tax: " << cost() <<endl;
            else
                os << " Price after tax: N/A" <<endl;
            os << " Quantity on Hand: " << m_currentUnits <<' ' << m_unitDesc << endl
               << " Quantity needed: " << m_neededUnits;
        }
        return os;
    }

    istream& Product::read(istream& is){
        //char sku[MAX_SKU+1];
        char* prodName;
        //char unit[MAX_UNIT+1];
        char _tax;
        double _price;
        int qtyHand;
        int qtyNeeded;

        prodName = new char[MAX_USER+1];

        if(!is.fail()) {
            cout << " Sku: ";
            is >> m_stockKeepingUnit;

            cout << " Name (no spaces): ";
            is >> prodName;
            name(prodName);

            cout << " Unit: ";
            is >> m_unitDesc;

            cout << " Taxed? (y/n): ";
            is >> _tax;

            if(!is.fail()) {
                m_error.clear();

                if (_tax) {
                    if(_tax=='y' || _tax=='Y')
                        m_taxable=true;
                    if(_tax=='n' || _tax =='N')
                        m_taxable=false;

                    if(_tax!='y' && _tax!='Y' && _tax!='n' && _tax !='N') {
                        is.setstate(ios::failbit);
                        m_error.message("Only (Y)es or (N)o are acceptable");
                        return is;
                    }
                }
            }else{
                is.setstate(ios::failbit);
                m_error.message("Only (Y)es or (N)o are acceptable");
                return is;
            }

            cout << " Price: ";
            is >> _price;
            if (is.fail()) {
                m_error.clear();
                is.setstate(ios::failbit);
                m_error.message("Invalid Price Entry");
                return is;
            }else
                price(_price);

            cout << " Quantity on hand: ";
            is >> qtyHand;
            if (is.fail()) {
                m_error.clear();
                is.setstate(ios::failbit);
                m_error.message("Invalid Quantity Entry");
                return is;
            }else
                quantity(qtyHand);

            cout << " Quantity needed: ";
            is >> qtyNeeded;
            cin.ignore();
            if (is.fail()) {
                m_error.clear();
                is.setstate(ios::failbit);
                m_error.message("Invalid Quantity Needed Entry");
                return is;
            }else
                needed(qtyNeeded);

            if (!is.fail()) {
                m_error.clear();
            }
        }
        delete [] prodName;
        return is;
    }
    fstream& Product::store(fstream& file, bool newLine) const{
        file << m_productType << COMMA << m_stockKeepingUnit << COMMA << m_productName << COMMA << m_unitDesc << COMMA
             << m_taxable << COMMA << m_price << COMMA << m_currentUnits << COMMA << m_neededUnits;
        if(newLine)
            file << endl;
        return file;
    }

    fstream& Product::load(fstream& file){
        char _sku[MAX_SKU];
        char _name[MAX_USER];
        char _unit[MAX_UNIT];
        double _price;
        int _current, _needed;
        char _tax;
        bool _taxable;

        if(file.is_open()){
            file.getline(_sku, MAX_SKU, COMMA);
            file.getline(_name, MAX_USER, COMMA);
            file.getline(_unit, MAX_UNIT, COMMA);
            file >> _tax;

            if(_tax == '1')
                _taxable = true;
            if(_tax == '0')
                _taxable = false;

            file.ignore();
            file >> _price;
            file.ignore();
            file >> _current;
            file.ignore();
            file >> _needed;
            file.ignore();

            *this = Product(_sku, _name, _unit, _current, _taxable, _price, _needed);
        }
        return file;
    }

    //helper functions
    ostream& operator<<(ostream& os, const iProduct& obj){
        return obj.write(os, true);
    }
    
    istream& operator>>(istream& is, iProduct& obj){
        obj.read(is);
        return is;
    }
    
    double operator+=(double& cost, const iProduct& obj){
        return cost + obj.total_cost();
    }
}
