//
//  Unsummon.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Unsummon.hpp"
#include "player.hpp"


Unsummon::Unsummon(string name, int cost, string description, player *p1, player *p2, string type):spell(name, cost, description,p1,p2,type){}
Unsummon::~Unsummon(){}

void Unsummon::unsummon(minion &other){
    if(this->gethandposition() == -1){cout<<"You don't have Unsummon in your hand"<<endl; return;}
    if(p1->getmagic() >= 1){
        p1->changemagic("minus", 1);
        other.back_to_hand();
    } else {
        cout<<"No enough magic for Unsummon"<<endl;
    }
}
