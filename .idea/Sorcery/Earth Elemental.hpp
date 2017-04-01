//
//  Earth Elemental.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Earth_Elemental_hpp
#define Earth_Elemental_hpp

#include <iostream>
#include "minion.hpp"

class EarthElemental:public minion{
public:
    EarthElemental(string name, int cost, string description, player *p1, player *p2, string type, int action, int defence, int attack, int buffamount);
    ~EarthElemental();
};

#endif /* Earth_Elemental_hpp */
