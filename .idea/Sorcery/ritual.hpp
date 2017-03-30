//
//  ritual.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef ritual_hpp
#define ritual_hpp

#include <iostream>
#include "card.hpp"
using namespace std;

class ritual: public card{
    int cost;
    string name;
public:
    ritual();
    virtual ~ritual();
    virtual void changehealth(string how, int much);
    virtual void changeattack(string how, int much);
    virtual void useability();
};

#endif /* ritual_hpp */
