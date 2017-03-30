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
#include <vector>
using namespace std;

class minion;

class grave{
    int amount;
    vector<minion> realgrave;
public:
    grave();
    ~grave();
};

#endif /* Grave_hpp */
