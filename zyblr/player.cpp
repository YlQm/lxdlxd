//
//  player.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include <iostream>
#include "player.hpp"
using namespace std;

player::player() : magic{0}, name{""}, health{20}, h{nullptr}, g{nullptr}, bf{nullptr}{}

player::~player(){}

string player::getname(){
    return name;
}

int player::getmagic(){
    return magic;
}

int player::gethealth(){
    return health;
}

void player::setname(string inputname){
    name = inputname;
}

void player::changehealth(string how, int much){
    if (how == "plus"){
        health += much;
    } else {
        health -= much;
    }
}
void player::changemagic(string how, int much){
    if (how == "plus"){
        magic += much;
    } else {
        magic -= much;
    }
}

