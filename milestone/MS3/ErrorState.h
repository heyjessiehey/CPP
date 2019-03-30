//
//  ErrorState.h
//  ms2
//
//  Created by Gayeon Ko on 2018-03-20.
//  Copyright © 2018 (Jessie) Gayeon Ko. All rights reserved.
//
//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Milestone3

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <iostream>

namespace AMA {
    class ErrorState{
        
        char* m_message;
        
        void setEmpty();
        
    public:
        
        explicit ErrorState(const char* errorMessage = nullptr);
        ErrorState(const ErrorState& em) = delete;
        ErrorState& operator=(const ErrorState& em) = delete;
        
        virtual ~ErrorState();
        
        void clear();
        bool isClear() const;
        void message(const char* str);
        const char* message()const;
    };
    std::ostream& operator<<(std::ostream& os, const ErrorState& msg);
}


#endif
