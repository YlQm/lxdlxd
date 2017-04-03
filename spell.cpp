//
//  spell.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "spell.hpp"
#include "player.hpp"
#include "minion.hpp"
#include "ritual.hpp"

spell::spell(string name, int cost, string description, player *p1, player *p2,string type):card{name, cost, description, p1, p2,type}{}
spell::~spell(){}

void spell::being_destroy(){
    p1->destroy_hand_card(*this);
}


