//
//  Recharge.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Recharge.hpp"

Recharge::Recharge() : name{"Recharge"}, cost{1}, description{"Your ritual gains 3 charges"}{}
Recharge::~Recharge(){}

string Recharge::getdescription(){
    return description;
}

void Recharge::recharge(ritual &other){}
