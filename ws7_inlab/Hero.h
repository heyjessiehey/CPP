//
//  Hero.h
//  ws7_inlab
//
//  Created by Gayeon Ko on 2018-03-19.
//  Copyright © 2018 (Jessie) Gayeon Ko. All rights reserved.
//
//  Derived Classes
//  Student ID  : 040 704 124
//  Email       : gko4@myseneca.ca
//  Section     : OPP244SGG
//

#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {
    
    const int SIZE = 41;
    const int max_rounds = 100;
    
    class Hero{
        char m_heroName[SIZE];
        int m_health;
        int m_attackStrength;
        
        bool isEmpty() const;
        
    public:
        Hero();
        Hero(const char [], int, int);
        
        void operator-=(int attack);
        bool isAlive() const;
        int attackStrength() const;
        const char* getName() const;
       
        friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
    };
    const Hero& operator*(const Hero& first, const Hero& second);
}

#endif
