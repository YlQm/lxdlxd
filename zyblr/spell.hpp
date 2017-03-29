//
//  spell.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef spell_hpp
#define spell_hpp

#include <iostream>
#include "card.hpp"
using namespace std;

class spell: public card{
    int cost;
    string name;
public:
    spell();
    virtual ~spell();
    virtual void changehealth(string how, int much);
    virtual void changeattack(string how, int much);
    virtual void useability();
};

#endif /* spell_hpp */
