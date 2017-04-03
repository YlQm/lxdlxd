//
//  minion.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "minion.hpp"
#include "player.hpp"
#include "enchantment.hpp"

minion::minion(string name, int cost, string description, player *p1, player *p2,string type, int action, int defence, int attack, int buffamount,int activated_ability_cost):card{name, cost, description, p1, p2, type}, bfposition{-1}, action{action}, defence(defence), attack(attack), buffamount{buffamount},activated_ability_cost{activated_ability_cost}{}

minion::~minion(){}

void minion::change_attack(string how, int much){
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

int minion::getattack(){
    return attack;
}

int minion::getdefence(){
    return defence;
}

void minion::being_destroy(){
    p1->destroy(*this);
}

int minion::getabilitycost(){
    return activated_ability_cost;
}

void minion::changeaction(string how, int much){
    if (how == "plus"){
        action += much;
    }
    else if (how == "minus"){
        action -= much;
    }
    else if (how == "times"){
        action *= much;
    }
    else if (how == "over"){
        action /= much;
    } else {
        cout<<"use valid string"<<endl;
    }
}

void minion::change_defence(string how, int much){
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
    if(action == 0){cout<<"This minion is lazy"<<endl; return;}
    if((bfposition != -1) && (other.getbfposiotion() != -1)){
        other.being_hit(attack);
        change_defence("minus", other.attack);
        --action;
    } else {
        cout<<"Minion is not in the battlefield"<<endl;
    }
}

void minion::being_hit(int otherattack){
    if(bfposition != -1){
        change_defence("minus", otherattack);
    } else {
        cout<<"This attacked minion is not in the battlefield"<<endl;
    }
}

void minion::hit(player &other){
    other.changehealth("minus", attack);
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

const vector<enchantment*>& minion::getbuff(){
    return buff;
}

int minion::get_buff_amount(){
    return buffamount;
}

void minion::add_buff(enchantment &other){
    buff.at(buffamount) = &other;
    ++buffamount;
}

void minion::get_enrage(){
    if(p1->getmagic() < 2){cout<<"player1 doesn't have enough magic for Enrage"<<endl; return;}
    p1->changemagic("minus", 2);
    change_defence("times", 2);
    change_attack("times", 2);
}

void minion::get_strength(){
    if(p1->getmagic() < 1){cout<<"player1 doesn't have enough magic for GiantStrength"<<endl; return;}
    p1->changemagic("minus", 1);
    change_attack("plus", 2);
    change_attack("plus", 2);
}

void minion::destroy_top_enchantment(){
    enchantment *temp = buff.at(buff.size() - 1 );
    delete temp;
    buff.pop_back();
    --buffamount;
}

void minion::add_action(){
    ++action;
}

void minion::silence(bool zyb){
    if(p1->getmagic() < 1){cout<<"player1 doesn't have enough magic for Silence"<<endl; return;}
    p1->changemagic("minus", 1);
    acability = zyb;
}
