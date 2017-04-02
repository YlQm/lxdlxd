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

void Blizzard::using_ability(){
        p1->aoe("minus", 2);
        p2->aoe("minus", 2);
}

