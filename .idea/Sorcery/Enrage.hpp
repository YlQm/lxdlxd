//
//  Enrage.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Enrage_hpp
#define Enrage_hpp

#include <iostream>
#include "enchantment.hpp"

class Enrage:public enchantment{
public:
    Enrage(string name, int cost, string description, player *p1, player *p2,string type, string a, string d);
    ~Enrage();
    void enrage();
    void being_destroy() override;
    void using_ability() override;
};

#endif /* Enrage_hpp */
