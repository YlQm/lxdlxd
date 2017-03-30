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

class Banish{
    int cost;
    string name;
    string description;
public:
    Banish();
    ~Banish();
    string getdescription();
    
    //real work
    void banish(minion &other);
    void banish(ritual &other);
};

#endif /* Banish_hpp */
