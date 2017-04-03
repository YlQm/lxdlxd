//
//  Recharge.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Recharge.hpp"
#include "player.hpp"

Recharge::Recharge(string name, int cost, string description, player *p1, player *p2, string type):spell(name, cost, description,p1,p2,type){}
Recharge::~Recharge(){}



void Recharge::using_ability(){
    p1->change_ritual_charge("plus", 3);
}

void Recharge::using_ability(minion &other){}
void Recharge::using_ability(ritual &other){}

