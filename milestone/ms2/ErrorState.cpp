//
//  ErrorState.cpp
//  ms2
//
//  Created by Gayeon Ko on 2018-03-20.
//  Copyright © 2018 (Jessie) Gayeon Ko. All rights reserved.
//
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Milesstone2

#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std;

namespace AMA {
    void ErrorState::setEmpty(){
        m_message = nullptr;
    }
    
    ErrorState::ErrorState(const char* errorMessage){
        if(errorMessage != nullptr){
            m_message = new char[strlen(errorMessage) +1];
            strcpy(m_message, errorMessage);
        }else
            setEmpty();
    }
    
    ErrorState::~ErrorState(){
        delete [] m_message;
    }
    
    void ErrorState::clear(){
        delete [] m_message;
        setEmpty();
    }
    
    bool ErrorState::isClear() const{
        return m_message == nullptr;
    }
    
    void ErrorState::message(const char* str){
        delete [] m_message;
        m_message = new char[strlen(str) +1];
        strcpy(m_message, str);
    }
    
    const char* ErrorState::message() const{
        return m_message;
    }
    
    ostream& operator<<(ostream& os, const ErrorState& msg){
        if(!msg.isClear()){
            os << msg.message();
        }
        return os;
    }
}
