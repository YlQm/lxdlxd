//
//  Unsummon.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Unsummon.hpp"
#include "player.hpp"
#include "minion.hpp"


Unsummon::Unsummon(string name, int cost, string description, player *p1, player *p2, string type):spell(name, cost, description,p1,p2,type){}
Unsummon::~Unsummon(){}

void Unsummon::using_ability(minion &other){
        other.back_to_hand();
}

void Unsummon::using_ability(ritual &other){}

void Unsummon::using_ability(){}
