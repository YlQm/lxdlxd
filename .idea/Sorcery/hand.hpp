//
//  hand.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef hand_hpp
#define hand_hpp

#include <iostream>
#include <vector>
using namespace std;

class card;

class hand{
    const int maxhandcard = 5;
    int amount;
    vector<card> realhand;
public:
    hand();
    ~hand();
    bool checkfull();
};

#endif /* hand_hpp */
