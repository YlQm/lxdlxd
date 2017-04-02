//
//  Haste.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Haste_hpp
#define Haste_hpp

#include <iostream>
#include "enchantment.hpp"

class Haste:public enchantment{
    bool added = false;
public:
    Haste(string name, int cost, string description, player *p1, player *p2,string type, string a, string d);
    ~Haste();
    void using_ability() override;
    void is_added();
};

#endif /* Haste_hpp */
