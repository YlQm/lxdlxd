//
//  Banish.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Banish.hpp"
#include "player.hpp"

Banish::Banish(string name, int cost, string description, player *p1, player *p2, string type):spell{name, cost, description, p1, p2, type}{}
Banish::~Banish(){}

void Banish::banish(minion &other){
    if(this->gethandposition() == -1){cout<<"You don't have Banish in your hand"<<endl; return;}
    if(p1->getmagic() >= 2){
        p1->changemagic("minus", 2);
        other.being_destroy();
        p1->destroy_hand_card(*this);
    } else {
        cout<<"No enough magic for Banish"<<endl;
    }
}

void Banish::banish(ritual &other){
    if(this->gethandposition() == -1){cout<<"You don't have Banish in your hand"<<endl; return;}
    if(p1->getmagic() >= 2){
        p1->changemagic("minus", 2);
        other.being_destroy();
        p1->destroy_hand_card(*this);
    } else {
        cout<<"No enough magic for Banish"<<endl;
    }
}

