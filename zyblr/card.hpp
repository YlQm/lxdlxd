//
//  card.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

#include <iostream>
#include <string>
#include "model.hpp"
using namespace std;

class card: public model {
    int cost;
    string name;
public:
    card();
    virtual ~card();
    
    //pure virtual since all cards are specific cards: minion spell enchantment ritual
    virtual void changehealth(string how, int much) =  0;
    virtual void changeattack(string how, int much) = 0;
    virtual void useability() = 0;
};

#endif /* card_hpp */
