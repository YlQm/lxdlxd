//
//  minion.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef minion_hpp
#define minion_hpp

#include <iostream>
#include "card.hpp"

class minion: public card{
    int action;
    int defence;
    int attack;
    int bfposition;
public:
    minion(string name, int cost, string description, player *p1, player *p2, int action, int defence, int attack);
    virtual ~minion();
    virtual void changedefence(string how, int much);
    virtual void changeattack(string how, int much);
    virtual void hit(minion &other);
    virtual void hit(player &other);
    virtual void being_hit (int otherattack);
    virtual void being_destroy();
    virtual bool isdead();
    virtual int getbfposiotion();
    virtual void setbfposition(int newposition);
};

#endif /* minion_hpp */

