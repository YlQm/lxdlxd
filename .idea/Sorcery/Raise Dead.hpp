//
//  Raise Dead.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Raise_Dead_hpp
#define Raise_Dead_hpp

#include <iostream>
#include "spell.hpp"
using namespace std;

class RaiseDead{
    int cost;
    string name;
    string description;
public:
    RaiseDead();
    ~RaiseDead();
    string getdescription();
    
    //real work
    void raisedead();
};

#endif /* Raise_Dead_hpp */
