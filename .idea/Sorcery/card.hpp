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
using namespace std;

class card {
    int cost;
    string name;
    int handposition;
public:
    card();
    virtual ~card();
    virtual gethandposition();
    virtual sethandposition(int newposition);
};

#endif /* card_hpp */
