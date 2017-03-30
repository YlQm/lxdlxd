//
//  Recharge.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Recharge_hpp
#define Recharge_hpp

#include <iostream>
#include "spell.hpp"
#include "ritual.hpp"
using namespace std;

class Recharge{
    int cost;
    string name;
    string description;
public:
    Recharge();
    ~Recharge();
    string getdescription();
    
    //real work
    void recharge(ritual &other);
};

#endif /* Recharge_hpp */
