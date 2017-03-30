//
//  minion.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "minion.hpp"
#include "player.hpp"

minion::minion() : name{""}, cost{0}, defence{0}, attack{0}, action{0}, bfposition{-1}, handposition{-1}{}

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
    if((bfposition != -1) && (other.getbfposiotion() != -1)){
        other.being_hit(attack);
        changedefence("minus", other.attack);
    } else {
        cout<<"Minion is not in the battlefield"<<endl;
    }
}

void minion::being_hit(int otherattack){
    if(bfposition != -1){
        changedefence("minus", otherattack);
    } else {
        cout<<"This attacked minion is not in the battlefield"<<endl;
    }
}

bool minion::isdead(){
    return defence <= 0;;
}

int minion::getbfposiotion(){
    return bfposition;
}

void minion::setbfposition(int newposition){
    bfposition = newposition;
}

int minion::gethandposiotion(){
    return handposition;
}

void minion::sethandposition(int newposition){
    handposition = newposition;
}
