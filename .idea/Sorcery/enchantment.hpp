//
//  enchantment.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef enchantment_hpp
#define enchantment_hpp

#include <iostream>
#include "card.hpp"
#include <string>
using namespace std;

class minion;
class enchantment: public card{
    minion *target;
public:
    enchantment(string name, int cost, string description, player *p1, player *p2);
    virtual ~enchantment();
};

#endif
