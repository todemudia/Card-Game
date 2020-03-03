//
//  Friend.cpp
//  assOne
//  Name: Triumph Joshua Odemudia
//  ID: 201094546
//  Created by Triumph Joshua Odemudia on 28/03/2017.
//  Copyright © 2017 Triumph Joshua Odemudia. All rights reserved.
//

#include "Friend.hpp"
#include <iostream>

using namespace std;

Friend::Friend(string s, int x, int y, string t){
    
    name = s;
    strength = x;
    intelligence = y;
    spell = t;
}

//Overrides the printCharacter method from GameCharacter
void Friend::printCharacter(){
    
    cout << "Type: Friend" << endl;
    cout << "Name: " << name << endl;
    cout << "Strength: " << strength << endl;
    cout << "Intelligence: " << intelligence<< endl;
    cout << "Spell: " << spell << endl;
    cout << "\n";
}
