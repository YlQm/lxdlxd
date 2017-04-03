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

player::player(string name) : magic{3}, name{name}, health{20}, max_magic{3}, hand{},  battlefield{}, grave{},  r(nullptr), ritual_exist(false), turn{false}{}


player::~player(){
    hand.clear();
    battlefield.clear();
    grave.clear();
}


const string player::getname(){
    return name;
}

const vector<card*> player::gethand(){return hand;}
const vector<minion*> player::getbattlefield(){return battlefield;}
const vector<minion*> player::getgrave(){return grave;}
ritual* player::getritual(){return r;}

const int player::getmagic(){
    return magic;
}


const int player::gethealth(){
    return health;
}

void player::setname(string inputname){
    name = inputname;
}

void player::setdeck(vector<card*> newdeck){
    deck = newdeck;
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
        grave.push_back(temp);
    } else {
        cout<<"Can't see the minion in your battlefield"<<endl;
    }
}

void player::summon(minion &other){
    if(battlefield.size() >= 5){
        cout<<"Max minions summoned"<<endl;
    } else {
        if(other.gethandposition() != -1){
            hand.erase(hand.begin() + other.gethandposition());
            other.sethandposition(-1);
            battlefield.push_back(&other);
            other.setbfposition(battlefield.size());
            changemagic("minus", other.getcost());
        } else {
            cout<<"You don't have this card in your hand"<<endl;
        }
    }
}

void player::reorder_hand(){
    for(int i = 0; i <hand.size();i++){
        hand.at(i)->sethandposition(i);
    }
}

void player::draw(){
    if(hand.size() >= 5){
        cout<<name<<"'s hand is full, can't draw"<<endl;
    } else {
        if(deck.size() <= 0){
            //this->changehealth("minus", deckamount);
            //--deckamount;  疲劳
            cout<<"No cards"<<endl;
        } else {
            int newposition = hand.size();
            card *temp = deck.at(deck.size() - 1);
            temp->sethandposition(newposition);
            hand.push_back(temp);
            deck.pop_back();
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


void player::bring_back(minion &other){
    int record = other.getbfposiotion();
    battlefield.erase(battlefield.begin() + record);
    for(int i = 0; i < other.getbuff().size(); i++){
        other.destroy_top_enchantment();
    }
    if(hand.size() >= 5){
        delete &other;
    } else {
        hand.push_back(&other);
        other.setbfposition(-1);
        other.sethandposition(hand.size());
    }
}

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
    cout<<"destroy target card successfully"<<endl;
}


void player::aoe(string how, int much){
    for(int i = 0; i < battlefield.size(); i++){
        battlefield.at(i)->change_defence(how, much);
    }
    cout<<"You've already dealed "<<much<<" damage to all minions on your battlefield"<<endl;
}

void player::play(int i){
    if(i > hand.size()){
        cout<<"You don't have that card in your hand"<<endl;
    } else {
        card *temp = hand.at(i - 1);
        if(temp->getcost() > magic){
            cout<<"You don't have enough magic for that card's cost"<<endl;
        } else {
            magic -= temp->getcost();
            if((temp->gettype() == "no ability minion")||(temp->gettype() == "triggered ability minion")
            || (temp->gettype() == "activated ability minion")){
                minion *m = dynamic_cast<minion*>(temp);
                if(m){
                    summon(*m);
                    reorder_hand();
                } else {
                    cout<<"casting error"<<endl;
                }
            }
            else if(temp->gettype() == "ritual"){
                ritual *ri = dynamic_cast<ritual*>(temp);
                if(ri){
                    r = ri;
                    ritual_exist = true;
                    hand.erase(hand.begin() + temp->gethandposition());
                    temp->sethandposition(-1);
                    reorder_hand();
                }else{
                    cout<<"casting error"<<endl;
                }
            }
            else if(temp->gettype() == "non-target spell"){
                spell *spl = dynamic_cast<spell*>(temp);
                if(spl){
                    spl->using_ability();
                    hand.erase(hand.begin() + temp->gethandposition());
                    temp->sethandposition(-1);
                    reorder_hand();
                } else {
                    cout<<"casting error"<<endl;
                }
            }
        }
    }
}

void player::play(int i, string whichplayer, int j){
    if(i > hand.size()){cout<<"You don't have that card in your hand"<<endl;return;}
    else {
        card *temp = hand.at(i - 1);
        if(temp->getcost() > magic){
            cout<<"You don't have enough magic for that card's cost"<<endl;
            return;
        } else {
            magic -= temp->getcost();
            if((temp->gettype() == "enchantment")||(temp->gettype() == "enchantment with attack defence")){
                enchantment* en = dynamic_cast<enchantment*>(temp);
                if(en){
                    if(whichplayer == "player1"){
                        if(j > battlefield.size()){
                            cout<<"You can't modify unexisting minion"<<endl;
                            return;
                        } else {
                            en->settarget(*battlefield.at(j - 1));
                            en->using_enability();
                            battlefield.at(j - 1)->add_buff(*en);
                            destroy_hand_card(*en);
                            return;
                        }
                    } else {
                        if(j > en->getenemy()->battlefield.size()){
                            cout<<"You can't modify unexisting minion"<<endl;
                            return;
                        } else {
                            en->settarget(*en->getenemy()->battlefield.at(j - 1));
                            en->using_enability();
                            en->getenemy()->battlefield.at(j - 1)->add_buff(*en);
                            destroy_hand_card(*en);
                            return;
                        }
                    }
                } else {
                    cout<<"casting error"<<endl;
                    return;
                }
            }
            else if(temp->gettype() == "target spell"){
                spell *sp = dynamic_cast<spell*>(temp);
                if(sp){
                    if(whichplayer == "player1"){
                        if(j > battlefield.size()){
                            cout<<"You can't modify unexisting minion"<<endl;
                            return;
                        } else {
                            if(j == -1){
                                sp->using_ability(*r);
                                destroy_hand_card(*sp);
                                delete sp;
                                return;
                            } else {
                                sp->using_ability(*battlefield.at(j - 1));
                                destroy_hand_card(*sp);
                                delete sp;
                                return;
                            }
                        }
                    } else {
                        if(j > sp->getenemy()->battlefield.size()){
                            cout<<"You can't modify unexisting minion"<<endl;
                            return;
                        } else {
                            if(j == -1){
                                sp->using_ability(*sp->getenemy()->getritual());
                                destroy_hand_card(*sp);
                                delete sp;
                                return;
                            } else {
                                sp->using_ability(*sp->getenemy()->getbattlefield().at(j - 1));
                                destroy_hand_card(*sp);
                                delete sp;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

//Remember, just for test mod
void player::discard(int i){
    if(i > hand.size()){
        cout<<"You don't have that card"<<endl;
        return;
    } else {
        card *temp = hand.at(i - 1);
        hand.erase(hand.begin() + i - 1);
        delete temp;
    }
}


void player::attack(int i){
    if(i > battlefield.size()){
        cout<<"You don't have this minion"<<endl;
    } else {
        battlefield.at(i - 1)->hit(*battlefield.at(i - 1)->getenemy());
    }
}


void player::attack(int i, int j){
    if(i > hand.size()){
        cout<<"You don't have that minion"<<endl;
        return;
    } else {
        minion *temp = battlefield.at(i - 1);
        if(j > temp->getenemy()->getbattlefield().size()){
            cout<<"He doesn't have that minion"<<endl;
            return;
        } else {
            temp->hit(*temp->getenemy()->getbattlefield().at(j - 1));
        }
    }
}


void player::reset_action(){
    for(int i =0; i<battlefield.size();i++){
        battlefield.at(i)->add_action();
    }
}

void player::reset_magic(){
    magic = max_magic;
}

void player::add_max_magic(){
    ++max_magic;
}





