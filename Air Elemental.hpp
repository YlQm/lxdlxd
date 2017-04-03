//
//  Air Elemental.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Air_Elemental_hpp
#define Air_Elemental_hpp

#include <iostream>
#include "minion.hpp"

class AirElemental:public minion{
public:
    AirElemental(string name, int cost, string description, player *p1, player *p2, string type, int action, int defence, int attack, int buffamount,int activated_ability_cost);
    ~AirElemental();
};

#endif /* Air_Elemental_hpp */
