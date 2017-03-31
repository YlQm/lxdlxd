//
//  Banish.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Banish.hpp"

Banish::Banish(string name, int cost, string description, player *p1, player *p2):spell(name, cost, description,p1,p2){}

Banish::~Banish(){}

void Banish::banish(minion &other){}

void Banish::banish(ritual &other){}

