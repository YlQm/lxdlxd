//
//  card.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "card.hpp"

card::card() : name{""}, cost{0}, handposition{-1}{}

card::~card(){}

int card::gethandposition(){
    return handposition;
}

void card::sethandposition(int newposition){
    handposition = newposition;
}
