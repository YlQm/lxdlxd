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

class Disenchant{
    int cost;
    string name;
    string description;
public:
    Disenchant();
    ~Disenchant();
    string getdescription();
    
    //real work
    void disenchant(minion &other);
};

#endif /* Disenchant_hpp */
