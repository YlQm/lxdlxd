//
//  Earth Elemental.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Earth Elemental.hpp"


EarthElemental::EarthElemental(string name, int cost, string description, player *p1, player *p2, string type, int action, int defence, int attack,int buffamount,int activated_ability_cost): minion{name, cost, description, p1, p2, type, action, defence, attack,buffamount,activated_ability_cost}{}

EarthElemental::~EarthElemental(){}
