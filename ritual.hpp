//
//  ritual.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef ritual_hpp
#define ritual_hpp

#include <iostream>
#include "card.hpp"
using namespace std;

class minion;

class ritual: public card{
protected:
    int acti_cost;
    int charge;
public:
    ritual(string name, int cost, string description, player *p1, player *p2, string type,int acti_cost, int charge);
    virtual ~ritual();
    void being_destroy();
    void change_charge(string how, int much);
    virtual void useability(minion &)=0;
    int getcharge();
    int getritualcost();
};




class DarkRitual: public ritual{
public:
    DarkRitual(string name, int cost, string description, player *p1, player *p2, string type,int acti_cost, int charge);
    ~DarkRitual();
    void useability(minion &)override;
};


class Standstill: public ritual{
public:
    Standstill(string name, int cost, string description, player *p1, player *p2, string type,int acti_cost, int charge);
    ~Standstill();
    void useability(minion &)override;
};

class AuraofPower: public ritual{
public:
    AuraofPower(string name, int cost, string description, player *p1, player *p2, string type,int acti_cost, int charge);
    ~AuraofPower();
    void useability(minion &)override;
};


#endif /* ritual_hpp */
