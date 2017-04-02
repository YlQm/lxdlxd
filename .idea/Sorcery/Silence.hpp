//
//  Silence.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Silence_hpp
#define Silence_hpp

#include <iostream>
#include "enchantment.hpp"

class Silence:public enchantment{
public:
    Silence(string name, int cost, string description, player *p1, player *p2,string type, string a, string d);
    ~Silence();
    void being_destroy() override;
    void using_ability() override;
};

#endif /* Silence_hpp */
