#ifndef enchantment_hpp
#define enchantment_hpp

#include <iostream>
#include "card.hpp"
using namespace std;

class enchantment: public card{
    int cost;
    string name;
    card *target;
public:
    enchantment(card *card);
    virtual ~enchantment();
    virtual void useability();
};

#endif