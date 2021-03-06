//
//  Blizzard.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Blizzard_hpp
#define Blizzard_hpp

#include <iostream>
#include "spell.hpp"
using namespace std;

class Blizzard:public spell{
public:
    Blizzard(string name, int cost, string description, player *p1, player *p2, string type);
    ~Blizzard();
    
    //real work
    void using_ability(minion &other)override;
    void using_ability(ritual &other)override;
    void using_ability()override;
};

#endif /* Blizzard_hpp */
