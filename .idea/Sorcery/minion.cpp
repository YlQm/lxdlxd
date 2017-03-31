//
//  minion.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "minion.hpp"
#include "player.hpp"

minion::minion(string name, int cost, string description, player *p1, player *p2, int action, int defence, int attack):card{name, cost, description, p1, p2}, bfposition{-1}, action{action}, defence(defence), attack(attack){}

minion::~minion(){}

void minion::changeattack(string how, int much){
    if (how == "plus"){
        attack += much;
    } else {
        attack -= much;
    }
}

void minion::being_destroy(){
    p1->destroy(*this);
}

void minion::changedefence(string how, int much){
    if (how == "plus"){
        defence += much;
    } else {
        defence -= much;
        if(defence <= 0){
            being_destroy();
        }
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
