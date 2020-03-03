//
//  Foe.hpp
//  assOne
//  Name: Triumph Joshua Odemudia
//  Id: 201094546
//  Created by Triumph Joshua Odemudia on 28/03/2017.
//  Copyright © 2017 Triumph Joshua Odemudia. All rights reserved.
//

#ifndef Foe_hpp
#define Foe_hpp


#include "GameCharacter.hpp"

class Foe : public GameCharacter
{
private:
    int wrath;
    
public:
    Foe(string, int, int);
    virtual void printCharacter();
};

#endif /* Foe_hpp */
