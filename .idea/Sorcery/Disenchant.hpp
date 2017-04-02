//
//  Disenchant.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Disenchant_hpp
#define Disenchant_hpp

#include <iostream>
#include "spell.hpp"
#include "minion.hpp"
using namespace std;

class Disenchant:public spell{
public:
    Disenchant(string name, int cost, string description, player *p1, player *p2, string type);
    ~Disenchant();
    
    //real work
    void using_ability(minion &other)override;
};

#endif /* Disenchant_hpp */
