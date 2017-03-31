//
//  card.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "card.hpp"
#include "player.hpp"

card::card(string name, int cost, string description, player *p1, player *p2) : name{name}, cost{cost}, handposition{-1}, p1{p1}, p2{p2}, description(description){}

card::~card(){}

int card::gethandposition(){
    return handposition;
}

void card::sethandposition(int newposition){
    handposition = newposition;
}

string card::getdescription(){
    return description;
}
