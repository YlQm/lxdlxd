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

player::player(string name) : magic{3}, name{name}, health{20}, hand{}, handamount{0}, battlefield{},bfamount{0}, grave{}, graveamount{0}, deckamount{0}, r(nullptr), ritual_exist(false){}


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
        temp->setbfposition(-1);
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

void player::destroy_ritual(){
    delete r;
    r = nullptr;
    ritual_exist = false;
}

////////////////////////////////////////////////////////
void player::bring_back(minion &other){
    int record = other.getbfposiotion();
    battlefield.erase(battlefield.begin() + record);
    --bfamount;
    if(handamount >= 5){
        delete &other;
    } else {
        hand.push_back(&other);
        ++handamount;
        other.setbfposition(-1);
        other.sethandposition(hand.size());
    }
}              ///////enchantment cards!!!!!
///////////////////////////////////////////////////////////

void player::raise_dead(){
    if(grave.size() <= 0){
        cout<<"No dead minions, cannot play RaiseDead!"<<endl;
    } else {
        minion *temp = grave.at(grave.size() - 1);
        temp->set_defence(1);
        temp->setbfposition(battlefield.size());
        battlefield.push_back(temp);
        grave.pop_back();
    }
}

void player::change_ritual_charge(string how, int much){
    if(ritual_exist == true){
        if (how == "plus"){
            r->change_charge("plus", much);
        }
        else if (how == "minus"){
            r->change_charge("minus", much);
        }
        else if (how == "times"){
            r->change_charge("times", much);
        }
        else if (how == "over"){
            r->change_charge("over", much);
        } else {
            cout<<"use valid string"<<endl;
        }
    } else {
        cout<<"You don't have a ritual card working for you"<<endl;
    }
}

void player::destroy_hand_card(card &other){
    int record = other.gethandposition();
    if(record == -1){cout<<"You don't have this spell in your hand"<<endl; return;}
    card *temp = hand.at(record);
    temp->sethandposition(-1);
    hand.erase(hand.begin() + record);
    --handamount;
    cout<<"destroy target card successfully"<<endl;
}


void player::aoe(string how, int much){
    for(int i = 0; i < battlefield.size(); i++){
        battlefield.at(i)->changedefence(how, much);
    }
    cout<<"You've already dealed "<<much<<" damage to all minions on your battlefield"<<endl;
}
