//
//  Banish.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Banish.hpp"
#include "player.hpp"

Banish::Banish(string name, int cost, string description, player *p1, player *p2, string type):spell{name, cost, description, p1, p2, type}{}
Banish::~Banish(){}

void Banish::using_ability(minion &other){
        other.being_destroy();
}

void Banish::using_ability(ritual &other){
        other.being_destroy();
}

void Banish::using_ability(){}

