//
//  Grave.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef Grave_hpp
#define Grave_hpp

#include <iostream>
#include "Board.hpp"

class minion;

class Grave: public Board {
    int amount;
    vector<minion> realgrave;
public:
    Grave();
    ~Grave();
};

#endif /* Grave_hpp */
