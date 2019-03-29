//
//  SuperHero.h
//  ws7_athome
//
//  Created by Gayeon Ko on 2018-03-20.
//  Copyright © 2018 (Jessie) Gayeon Ko. All rights reserved.
//
//  Derived Classes
//  Student ID  : 040 704 124
//  Email       : gko4@myseneca.ca
//  Section     : OPP244SGG
//

#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"

namespace sict{
    class SuperHero : public Hero{
        int m_attackBonus;
        int m_defendStrength;
    
    public:
        SuperHero();
        SuperHero(const char*, int, int, int, int);

        int attackStrength() const;
        int defend() const;
    
    };
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif
