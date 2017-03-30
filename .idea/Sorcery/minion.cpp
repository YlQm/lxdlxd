//
//  minion.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "minion.hpp"
#include "player.hpp"

minion::minion() : name{""}, cost{0}, defence{0}, attack{0}, action{0}{}

minion::~minion(){}

void minion::changeattack(string how, int much){
    if (how == "plus"){
        attack += much;
    } else {
        attack -= much;
    }
}

void minion::changedefence(string how, int much){
    if (how == "plus"){
        defence += much;
    } else {
        defence -= much;
    }
}

void minion::hit(minion &other){
    other.being_hit(attack);
    changedefence("minus", other.attack);
}

void minion::being_hit(int otherattack){
    changedefence("minus", otherattack);
}

