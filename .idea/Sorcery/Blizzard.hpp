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

class Blizzard{
    int cost;
    string name;
    string description;
public:
    Blizzard();
    ~Blizzard();
    string getdescription();
    
    //real work
    void blizzard();
};

#endif /* Blizzard_hpp */
