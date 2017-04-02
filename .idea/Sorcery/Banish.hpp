//
//  Banish.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Banish_hpp
#define Banish_hpp

#include <iostream>
#include "spell.hpp"
#include "minion.hpp"
#include "ritual.hpp"
using namespace std;

class Banish:public spell{
public:
    Banish(string name, int cost, string description, player *p1, player *p2, string type);
    ~Banish();
    
    //real work
    void using_ability(minion &other)override;
    void using_ability(ritual &other)override;
};

#endif /* Banish_hpp */
