//
//  Recharge.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Recharge.hpp"
#include "player.hpp"

Recharge::Recharge(string name, int cost, string description, player *p1, player *p2, string type):spell(name, cost, description,p1,p2,type){}
Recharge::~Recharge(){}


void Recharge::recharge(ritual &other){
    if(this->gethandposition() == -1){cout<<"You don't have Recharge in your hand"<<endl; return;}
    if(p1->getmagic() >= 1){
        p1->changemagic("minus", 1);
        p1->change_ritual_charge("plus", 3);
    } else {
        cout<<"No enough magic for Unsummon"<<endl;
    }
}
