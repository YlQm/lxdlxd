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

class player;
class card {
protected:
    player *p1;
    player *p2;
    int cost;
    string name;
    int handposition;
    string description;
public:
    card(string name, int cost, string description, player *p1, player *p2);
    virtual ~card();
    virtual int gethandposition();
    virtual void sethandposition(int newposition);
    string getdescription();
};

#endif /* card_hpp */
