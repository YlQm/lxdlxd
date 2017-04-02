//
//  Silence.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Silence.hpp"
#include "minion.hpp"

Silence::Silence(string name, int cost, string description, player *p1, player *p2,string type, string a, string d):enchantment{name, cost, description, p1, p2, type,a,d}{}

Silence::~Silence(){
    target = nullptr;
}

void Silence::using_ability(){
    target->silence(false);
    target->add_buff(*this);
}

void Silence::being_destroy(){
    target->silence(true);
    target->destroy_top_enchantment();
}
