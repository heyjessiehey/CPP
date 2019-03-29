//
//  Hero.cpp
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

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {
    
    Hero::Hero(){
        m_heroName[0] = '\0';
        m_health = 0;
        m_attackStrength = 0;
    }
    
    Hero::Hero(const char name[], int health, int strength){
        bool valid = name[0] != '\0' && health > 0 && strength > 0;
        if(valid){
            strncpy(m_heroName, name, SIZE);
            m_heroName[SIZE -1] = '\0';
            m_health = health;
            m_attackStrength = strength;
        }else
            *this = Hero();
    }
    
    bool Hero::isEmpty() const{
        return m_heroName[0] == '\0' && m_health == 0 && m_attackStrength == 0;
    }
    
    // overloaded operator
    void Hero::operator-=(int attack){
        if(attack > 0 && m_health > 0){
            m_health -= attack;
            if(m_health <= 0)
                m_health = 0;
        }
    }
    
    bool Hero::isAlive() const{
        return m_health > 0;
    }
    
    int Hero::attackStrength() const{
        if(isEmpty())
            return 0;
        return m_attackStrength;
    }
    
    //the function allows the helper operator access data members
    const char* Hero::getName() const{
        return m_heroName;
    }

    //friend helper operator
    ostream& operator<<(std::ostream& os, const Hero& hero){
        if(hero.isEmpty())
            os << "No hero" << endl;
        else
            os << hero.m_heroName;
            
        return os;
    }
  
    // helper operator out side of class
    const Hero& operator*(const Hero& first, const Hero& second){
        int round = 0;
        Hero temp1 = first, temp2 = second, winner;
        
        for(int i =0; i<max_rounds && temp1.isAlive() && temp2.isAlive(); i++){
            temp1 -= temp2.attackStrength();
            temp2 -= temp1.attackStrength();
            round++;
        }
        
        if(!temp1.isAlive()){
            winner = temp2;
            cout << "Ancient Battle! " << first.getName() << " vs " <<
            second.getName() << " : Winner is " << winner <<
            " in " << round << " rounds." << endl;
            return second;
        }else if(!temp2.isAlive()){
            winner = temp1;
            cout << "Ancient Battle! " << first.getName() << " vs " <<
            second.getName() << " : Winner is " << winner <<
            " in " << round << " rounds." << endl;
            return first;
        }else
            return first;
    }
}
