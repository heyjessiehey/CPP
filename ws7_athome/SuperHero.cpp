//
//  SuperHero.cpp
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

#include <iostream>
#include "SuperHero.h"

using namespace std;

namespace sict {
    SuperHero::SuperHero() : Hero(){
        m_attackBonus = 0;
        m_defendStrength = 0;
    }
    
    SuperHero::SuperHero(const char name[], int health, int attack, int superAttack, int superDefend) : Hero(name, health, attack){
        bool valid = superAttack > 0 && superDefend > 0;
        if(valid){
            m_attackBonus = superAttack;
            m_defendStrength = superDefend;
        }else
            *this = SuperHero();
    }
    
    int SuperHero::attackStrength() const{
        if(Hero::isEmpty())
            return 0;
        return Hero::attackStrength() + m_attackBonus;
    }
    
    int SuperHero::defend() const{
        if(Hero::isEmpty())
            return 0;
        return m_defendStrength;
    }
    
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
        int round = 0;
        SuperHero temp1 = first, temp2 = second, winner;
        
        for(int i=0; i<max_rounds && temp1.isAlive() && temp2.isAlive(); i++){
            temp1 -= temp2.attackStrength() - temp1.defend();
            temp2 -= temp1.attackStrength() - temp2.defend();
            round++;
        }
        if(!temp1.isAlive()){
            winner = temp2;
            cout << "Super Fight! " << first.getName() << " vs " <<
            second.getName() << " : Winner is " << winner <<
            " in " << round << " rounds." << endl;
            return second;
        }else if(!temp2.isAlive()){
            winner = temp1;
            cout << "Super Fight! " << first.getName() << " vs " <<
            second.getName() << " : Winner is " << winner <<
            " in " << round << " rounds." << endl;
            return first;
        }else
            return first;
    }
}

