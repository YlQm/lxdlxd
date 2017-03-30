//
//  deck.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include <iostream>
#include "deck.hpp"
using namespace std;

deck::deck(): num{0}{}

deck::~deck(){
    theDeck.clear();
    realDeck.clear();
}

void deck::addtodeck(string newcard){
    theDeck.push_back(newcard);
}
