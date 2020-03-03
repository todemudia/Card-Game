//
//  main.cpp
//  assOne
//  Name: Triumph Joshua Odemudia
//  ID: 201094546
//  Created by Triumph Joshua Odemudia on 28/03/2017.
//  Copyright © 2017 Triumph Joshua Odemudia. All rights reserved.
//

#include <iostream>
#include "Friend.hpp"
#include "Foe.hpp"
#include <vector>

using namespace std;

/*************************** method declaration ***********************************/
void battleMessage(int, int);
void displayCharacters();
bool checkCharacters();
void mainMenuScreen();
string inputString();
void checkInput(int);
void draw(int, int);
void createFriend();
int getInput(int);
void createFoe();
void winner(int);
void loser(int);
void doBattle();
void gameOver();






vector <GameCharacter*> characters; //Used to store info for all chracters


/*************************** Main Function ***************************************/
int main() {

    int input = 0;
    int maxInput = 5;
    
    do{
        mainMenuScreen();
        input = getInput(maxInput);
        checkInput(input);
    }while (input != maxInput);
    
    return 0;
}//Main method

/*************************** Function definitons***********************************/

/* This Function displays the menu options to the user*/
void mainMenuScreen(){
    cout << "\nMain Menu\n" << endl;
    cout << "1) Create friend" << endl;
    cout << "2) Create foe" << endl;
    cout << "3) Display all Characters" << endl;
    cout << "4) Do battle" << endl;
    cout << "5) Quit\n" << endl;
    cout << "What would you like to do? " << endl;
}//mainMenuScreen

/* This Function gets the input from the user to be used for the menu options */
int getInput(int y){
    
    
    int x = 0;
    cin >> x;
    
    while (x < 0 || x > y){
        cout << "Invalid input, please enter a value from 0 to " << y << endl;
        cin >> x;
    }
    
    return x;
}//getInput

/* This functions creates an object of thread and adds it to the vector characters*/
void createFriend(){
    string name, spell;
    int maxInput = 10;
    int x, y;
    
    cout << "Enter name: " << endl;
    name = inputString();
    
    cout <<"Enter strength: " << endl;
    x = getInput(maxInput);
    
    cout <<"Enter intelligence: " << endl;
    y = getInput(maxInput);
    
    cout <<"Enter spell: " << endl;
    spell = inputString();
    
    characters.push_back(new Friend(name,x,y,spell));
}//createFriend

/* This function inputs a string*/
string inputString(){
    string wordInput;
    
    cin.ignore(); //Clears the buffer by getting rid of any lingering newline characters
    getline(cin, wordInput); // used getline instead of cin so it would get spaces in names
    
    return wordInput;
}

/* This function creates an object of type foe */
void createFoe(){
    string name;
    int maxInput = 10;
    int x, y;
    
    cout << "Enter name: " << endl;
    name = inputString();
    
    cout <<"Enter strength: " << endl;
    x = getInput(maxInput);
    
    cout <<"Enter wrath: " << endl;
    y = getInput(maxInput);

    characters.push_back(new Foe(name,x,y));
}//createFoe

/* this function prints a goodbye message */
void gameOver(){
    cout <<"\nThanks for Playing." << endl;
}//gameOver

/* This method displays all the characters currently in the vector*/
void displayCharacters(){
    int num = 1;
    if(characters.size() == 0){
        cout << "\nYou have no characters!" << endl;
    }
    
    vector<GameCharacter*> ::iterator i;
    for(i = characters.begin(); i != characters.end(); i++)
    {
        cout << num++ << ") " << endl;
        (*i)->printCharacter();
    }//for loop
}//displayCharacters

/* This function picks two characters in the vector and pits them agaisnt each other */
void doBattle(){
    int v1, v2;
    bool canBattle = false;
    
    canBattle = checkCharacters();
    while(canBattle == true){
        //Gets a random characters from 0 to vector size
        v1 = rand() % characters.size();
        v2 = rand() % characters.size();
    
        while (v2 == v1){//Makes sure different characters are selected
            v2 = rand() % characters.size();
        }//v2 == v1 while
    
        battleMessage(v1, v2);
    
        if (characters[v1]->getStr() > characters[v2]->getStr()){
            winner(v1);
            loser(v2);
        }//if
    
        else if (characters[v1]->getStr() < characters[v2]->getStr()){
            winner(v2);
            loser(v1);
        }//if else
    
        else {
            draw(v1,v2);
        }//else
        break;
    }//canBattle While loop
    
    
}//doBattle

/* This function prints out the name of characters about to battle*/
void battleMessage(int x, int y){
    cout << characters[x]->getName() << " will do battle with " << characters[y]->getName() << endl;
    cout << characters[x]->getName() << " has strength " << characters[x]->getStr() << ". ";
    cout << characters[y]->getName() << " has strength " << characters[y]->getStr() << ". " << endl;
    
}//battleMessage

/* prints out draw if both sides have the same stats*/
void draw(int x, int y){
    cout << characters[x]->getName() << " as drawn with " << characters[y]->getName();
    
}//draw

/* Prints out the winners name*/
void winner(int x){
    cout << characters[x]->getName() << " wins! ";
}//winner

/* Deletes the losers object and erases its space in the vector*/
void loser(int x){
    delete characters[x];
    characters.erase(characters.begin()+x);
}//loser

/* Checks the amount of characters in the vector, returns false if its less than 2*/
bool checkCharacters(){
    bool battle = false;
    
    if(characters.size() < 2){
        cout << "\ncannot do battle, too few characters." << endl;
        battle = false;
    }
    else battle = true;
    
    return battle;
}//checkCharacters

/* This function selects options based on the users input */
void checkInput(int x){
    switch(x){
        case 1 : createFriend();
            break;
        case 2 : createFoe();
            break;
        case 3 : displayCharacters();
            break;
        case 4 : doBattle();
            break;
        case 5 : gameOver();
            break;
    }//switch case

}//checkInput
