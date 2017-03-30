//
//  Banish.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Banish.hpp"

Banish::Banish() : name{"Banish"}, cost{2}, description{"Destroy target minion or ritual"}{}
Banish::~Banish(){}

string Banish::getdescription(){
    return description;
}

void Banish::banish(minion &other){}

void Banish::banish(ritual &other){}

