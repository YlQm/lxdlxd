//
//  Disenchant.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Disenchant.hpp"

Disenchant::Disenchant() :name{"Disenchant"},cost{1},description{"Destroy the top enchantment on target minion"}{}
Disenchant::~Disenchant(){}

string Disenchant::getdescription(){
    return description;
}

void Disenchant::disenchant(minion &other){}
