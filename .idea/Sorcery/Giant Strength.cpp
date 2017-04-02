//
//  Giant Strength.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Giant Strength.hpp"
#include "minion.hpp"

GiantStrength::GiantStrength(string name, int cost, string description, player *p1, player *p2,string type, string a, string d):enchantment{name, cost, description, p1, p2, type,a,d}{}

GiantStrength::~GiantStrength(){
    target = nullptr;
}

void GiantStrength::using_ability(){
    target->get_strength();
    target->add_buff(*this);
}

void GiantStrength::being_destroy(){
    target->changeaction("minus", 2);
    target->changedefence("minus", 2);
    target->destroy_top_enchantment();
}
