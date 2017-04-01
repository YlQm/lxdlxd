//
//  Blizzard.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Blizzard.hpp"
#include "player.hpp"

Blizzard::Blizzard(string name, int cost, string description, player *p1, player *p2, string type):spell(name, cost, description,p1,p2,type){}

void Blizzard::blizzard(){
    if(this->gethandposition() == -1){ cout<<"You don't have this card (Blizzard) in your hand"<<endl;
        return;}
    if(p1->getmagic() < 3){
        cout<<"You don't have enough magic for Blizzard"<<endl;
    } else {
        p1->changemagic("minus", 3);
        p1->aoe("minus", 2);
        p2->aoe("minus", 2);
        p1->destroy_hand_card(*this);
    }
}

