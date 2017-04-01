//
//  minion.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "minion.hpp"
#include "player.hpp"

minion::minion(string name, int cost, string description, player *p1, player *p2,string type, int action, int defence, int attack):card{name, cost, description, p1, p2, type}, bfposition{-1}, action{action}, defence(defence), attack(attack){}

minion::~minion(){}

void minion::changeattack(string how, int much){
    if (how == "plus"){
        attack += much;
    }
    else if (how == "minus"){
        attack -= much;
    }
    else if (how == "times"){
        attack *= much;
    }
    else if (how == "over"){
        attack /= much;
    } else {
        cout<<"use valid string"<<endl;
    }
}

void minion::being_destroy(){
    p1->destroy(*this);
}

void minion::changedefence(string how, int much){
    if (how == "plus"){
        defence += much;
    }
    else if (how == "minus"){
        defence -= much;
    }
    else if (how == "times"){
        defence *= much;
    }
    else if (how == "over"){
        defence /= much;
    } else {
        cout<<"use valid string"<<endl;
    }
    if(defence <= 0){
        being_destroy();
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

void minion::back_to_hand(){
    p1->bring_back(*this);
}

void minion::set_defence(int newdefence){
    defence = newdefence;
}

void minion::set_attack(int newattack){
    attack = newattack;
}
