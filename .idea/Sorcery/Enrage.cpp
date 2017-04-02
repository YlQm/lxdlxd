//
//  Enrage.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Enrage.hpp"
#include "minion.hpp"

Enrage::Enrage(string name, int cost, string description, player *p1, player *p2,string type, string a, string d):enchantment{name, cost, description, p1, p2, type, a, d}{}

Enrage::~Enrage(){
    target = nullptr;
}

void Enrage::using_ability(){
    target->get_enrage();
    target->add_buff(*this);
}

void Enrage::being_destroy(){
    target->changeaction("over", 2);
    target->changedefence("over", 2);
    target->destroy_top_enchantment();
}
