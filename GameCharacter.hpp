//
//  Game_character.hpp
//  assignment2
//  Name: Triumph Joshua Odemudia
//  ID: 201094546
//  Created by Triumph Joshua Odemudia on 28/03/2017.
//  Copyright © 2017 Triumph Joshua Odemudia. All rights reserved.
//

#ifndef GameCharacter_hpp
#define GameCharacter_hpp

#include <string>
using namespace std;



class GameCharacter {

//Fields for class
protected: //set as protected so subclasses can access the variable
    string name;
    int strength;
    
//Class Methods
public:

    //Declared virtual so it can be overwritten by sub classes
    virtual void printCharacter();
    
    //declared two getters for encapsulation
    int getStr(){return strength;};
    string getName(){return name;};

};
#endif /* GameCharacter_hpp */
