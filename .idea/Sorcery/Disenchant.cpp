//
//  Disenchant.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Disenchant.hpp"
#include "player.hpp"

Disenchant::Disenchant(string name, int cost, string description, player *p1, player *p2, string type):spell{name, cost, description, p1, p2, type}{}
Disenchant::~Disenchant(){}


void Disenchant::using_ability(minion &other){
        other.destroy_top_enchantment();
}

void Disenchant::using_ability(ritual &other){}
void Disenchant::using_ability(){}
