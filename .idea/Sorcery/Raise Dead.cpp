//
//  Raise Dead.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Raise Dead.hpp"
#include "player.hpp"

RaiseDead::RaiseDead(string name, int cost, string description, player *p1, player *p2, string type):spell(name, cost, description,p1,p2,type){}
RaiseDead::~RaiseDead(){}


void RaiseDead::using_ability(){
    p1->raise_dead();
}



