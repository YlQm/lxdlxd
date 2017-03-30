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
using namespace std;

class enchantment: public card{
    int cost;
    string name;
public:
    enchantment();
    virtual ~enchantment();
    virtual void changehealth(string how, int much);
    virtual void changeattack(string how, int much);
    virtual void useability();
};

#endif /* enchantment_hpp */
