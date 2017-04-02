//
//  Haste.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Haste.hpp"
#include "minion.hpp"

Haste::Haste(string name, int cost, string description, player *p1, player *p2,string type, string a, string d):enchantment{name, cost, description, p1, p2, type,a,d}{}

Haste::~Haste(){
    target = nullptr;
}

void Haste::using_ability(){
    target->add_action();
    if(added == false){
        target->add_buff(*this);
        added = true;
    }
}
