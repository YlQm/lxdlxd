//
//  Disenchant.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Disenchant.hpp"
#include "player.hpp"

Disenchant::Disenchant(string name, int cost, string description, player *p1, player *p2, string type):spell{name, cost, description, p1, p2, type}{}
Disenchant::~Disenchant(){}


void Disenchant::disenchant(minion &other){
    if(this->gethandposition() == -1){cout<<"You don't have Dienchant in your hand"<<endl; return;}
    if(p1->getmagic() >= 1){
        p1->changemagic("minus", 1);
        other.destroy_top_enchantment();
        p1->destroy_hand_card(*this);
    } else {
        cout<<"No enough magic for Disenchant"<<endl;
    }
}
