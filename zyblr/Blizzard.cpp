//
//  Blizzard.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Blizzard.hpp"

Blizzard::Blizzard() :name{"Blizzard"},cost{3},description{"Deal 2 damage to all minions"}{}
Blizzard::~Blizzard(){}

string Blizzard::getdescription(){
    return description;
}

void Blizzard::blizzard(){}
