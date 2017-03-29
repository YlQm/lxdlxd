//
//  Battlefield.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Battlefield_hpp
#define Battlefield_hpp

#include <iostream>
#include "Board.hpp"

class minion;

class Battlefield: public Board {
    const int maxamount = 5;//the max number of minions in Battlefield is 5.
    int amount;
    vector<minion> realfield;
public:
    Battlefield();
    ~Battlefield();
};

#endif /* Battlefield_hpp */
