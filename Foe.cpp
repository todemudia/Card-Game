//
//  Foe.cpp
//  assOne
//  Name: Triumph Joshua Odemudia
//  ID: 201094546
//  Created by Triumph Joshua Odemudia on 28/03/2017.
//  Copyright © 2017 Triumph Joshua Odemudia. All rights reserved.
//

#include "Foe.hpp"
#include <iostream>

using namespace std;

Foe::Foe(string s, int x, int y){
    
    name = s;
    strength = x;
    wrath = y;
}

//Overrides the printCharacter method from GameCharacter
void Foe::printCharacter(){
    
    cout << "Type: Foe" << endl;
    cout << "Name: " << name << endl;
    cout << "Strength: " << strength << endl;
    cout << "Wrath: " << wrath << endl;
    cout << "\n";
}
