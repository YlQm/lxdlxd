//
//  Unsummon.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Unsummon.hpp"


Unsummon::Unsummon() :name{"Unsummon"},cost{1},description{"Return target minion to its owner's hand"}{}
Unsummon::~Unsummon(){}

string Unsummon::getdescription(){
    return description;
}

void Unsummon::unsummon(minion &other){}
