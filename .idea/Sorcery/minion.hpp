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

class player;
class minion: public card{
    int action;
    int defence;
    int attack;
    int cost;
    string name;
public:
    minion();
    virtual ~minion();
    virtual void changedefence(string how, int much);
    virtual void changeattack(string how, int much);
    virtual void hit(minion &other);
    virtual void hit(player &other);
    virtual void being_hit (int otherattack);
};

#endif /* minion_hpp */

