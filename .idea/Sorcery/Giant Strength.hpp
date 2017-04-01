//
//  Giant Strength.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Giant_Strength_hpp
#define Giant_Strength_hpp

#include <iostream>
#include "enchantment.hpp"

class GiantStrength:public enchantment{
public:
    GiantStrength(string name, int cost, string description, player *p1, player *p2,string type);
    ~GiantStrength();
    void giantstrength();
    void being_destroy() override;
};

#endif /* Giant_Strength_hpp */
