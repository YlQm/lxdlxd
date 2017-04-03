//
//  ritual.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "ritual.hpp"
#include "player.hpp"

ritual::ritual(string name, int cost, string description, player *p1, player *p2, string type,int acti_cost, int charge): card(name,cost,description,p1,p2,type),acti_cost(acti_cost),charge(charge){}

ritual::~ritual(){}

void ritual::being_destroy(){
    p1->destroy_ritual();
}

void ritual::change_charge(string how, int much){
    if (how == "plus"){
        charge += much;
    }
    else if (how == "minus"){
        charge -= much;
    }
    else if (how == "times"){
        charge *= much;
    }
    else if (how == "over"){
        charge /= much;
    } else {
        cout<<"use valid string"<<endl;
    }
    if(charge <= 0){
        being_destroy();
    }
}

int ritual::getcharge(){
    return charge;
}
int ritual::getritualcost(){
    return acti_cost;
}
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

DarkRitual::DarkRitual(string name, int cost, string description, player *p1, player *p2, string type,int acti_cost, int charge): ritual(name,cost,description,p1,p2,type,acti_cost,charge){}
DarkRitual::~DarkRitual(){}

void DarkRitual::useability(minion &other){}


////////////////////////////////////////////////////
////////////////////////////////////////////////////

AuraofPower::AuraofPower(string name, int cost, string description, player *p1, player *p2, string type,int acti_cost, int charge): ritual(name,cost,description,p1,p2,type,acti_cost,charge){}
AuraofPower::~AuraofPower(){}

void AuraofPower::useability(minion &other){}


////////////////////////////////////////////////////
////////////////////////////////////////////////////

Standstill::Standstill(string name, int cost, string description, player *p1, player *p2, string type,int acti_cost, int charge): ritual(name,cost,description,p1,p2,type,acti_cost,charge){}
Standstill::~Standstill(){}

void Standstill::useability(minion &other){}
