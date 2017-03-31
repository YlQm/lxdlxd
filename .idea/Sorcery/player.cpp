//
//  player.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include <iostream>
#include "player.hpp"
using namespace std;

player::player(string name) : magic{3}, name{name}, health{20}, hand{}, handamount{0}, battlefield{},bfamount{0}, grave{}, graveamount{0}, deckamount{0}{}


player::~player(){
    hand.clear();
    battlefield.clear();
    grave.clear();
}


string player::getname(){
    return name;
}


int player::getmagic(){
    return magic;
}


int player::gethealth(){
    return health;
}

int player::gethandzmount(){
    return handamount;
}
int player::getbfamount(){
    return bfamount;
}
int player::getgraveamount(){
    return graveamount;
}
int player::getdeckamount(){
    return deckamount;
}
void player::setname(string inputname){
    name = inputname;
}


void player::changehealth(string how, int much){
    if (how == "plus"){
        health += much;
    } else {
        health -= much;
        if (health <= 0){
            throw name;
        }
    }
}

void player::changemagic(string how, int much){
    if (how == "plus"){
        magic += much;
    } else {
        magic -= much;
    }
}

void player::destroy(minion &other){
    int record = other.getbfposiotion();
    if(record != -1){
        minion *temp = battlefield.at(record);
        battlefield.erase(battlefield.begin() + record);
        --bfamount;
        grave.push_back(temp);
        ++graveamount;
    } else {
        cout<<"Can't see the minion in your battlefield"<<endl;
    }
}

void player::summon(minion &other){
    if(bfamount >= 5){
        cout<<"Max minions summoned"<<endl;
    } else {
        if(other.gethandposition() != -1){
            hand.erase(hand.begin() + other.gethandposition());
            other.sethandposition(-1);
            --handamount;
            battlefield.push_back(&other);
            other.setbfposition(bfamount);
            ++bfamount;
        } else {
            cout<<"You don't have this card in your hand"<<endl;
        }
    }
}

void player::draw(){
    if(handamount >= 5){
        cout<<name<<"'s hand is full, can't draw"<<endl;
    } else {
        if(deckamount <= 0){
            //this->changehealth("minus", deckamount);
            //--deckamount;  疲劳
            cout<<"No cards"<<endl;
        } else {
            int newposition = hand.size() - 1;
            card *temp = deck.at(deck.size() - 1);
            temp->sethandposition(newposition);
            hand.push_back(temp);
            deck.pop_back();
            --deckamount;
            ++handamount;
        }
    }
    
}

void player::add_magic(){
    ++magic;
}
