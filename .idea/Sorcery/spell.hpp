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

class minion;
class ritual;
class spell: public card{
public:
    spell(string name, int cost, string description, player *p1, player *p2, string type);
    virtual ~spell();
    virtual void being_destroy();
    virtual void being_used();
    virtual void using_ability(minion &other);
    virtual void using_ability(ritual &other);
    virtual void using_ability();
};

#endif /* spell_hpp */
