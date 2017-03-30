//
//  Unsummon.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Unsummon_hpp
#define Unsummon_hpp

#include <iostream>
#include "spell.hpp"
#include "minion.hpp"
using namespace std;

class Unsummon{
    int cost;
    string name;
    string description;
public:
    Unsummon();
    ~Unsummon();
    string getdescription();
    
    //real work
    void unsummon(minion &other);
};

#endif /* Unsummon_hpp */
