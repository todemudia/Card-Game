//
//  Friend.hpp
//  assOne
//  Name: Triumph Joshua Odemudia
//  ID: 201094546
//  Created by Triumph Joshua Odemudia on 28/03/2017.
//  Copyright © 2017 Triumph Joshua Odemudia. All rights reserved.
//

#ifndef Friend_hpp
#define Friend_hpp

#include "GameCharacter.hpp"

using namespace std;



class Friend: public GameCharacter
{
    private:
    int intelligence;
    string spell;
    
    public:
    Friend(string, int, int, string);
    virtual void printCharacter();
    
};
#endif /* Friend_hpp */
