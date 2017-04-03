//
//  enchantment.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "enchantment.hpp"

enchantment::enchantment(string name, int cost, string description,player *p1, player *p2, string type, string a, string d):card(name, cost, description, p1, p2,type), target{nullptr}, attack_buff{a}, defence_buff{d}{}

enchantment::~enchantment(){
    target = nullptr;
}

void enchantment::being_destroy(){
    target->destroy_top_enchantment();
}
string enchantment::get_attack(){
    return attack_buff;
}

string enchantment::get_defence(){
    return defence_buff;
}

void enchantment::settarget(minion &other){
    target = &other;
}

void enchantment::using_enability(){}
