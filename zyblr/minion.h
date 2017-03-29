
#ifndef MINION_H
#define MINION_H

#include <iostream>
#include "card.hpp"

class minion: public card{
    int action;
    int health;
    int attack;
    int cost;
    string name;
public:
    minion();
    virtual ~minion();
    virtual void changehealth(string how, int much);
    virtual void changeattack(string how, int much);
    virtual void hit(minion &other);
    virtual void hit(palyer &p) = 0;
    virtual void useability();
};

#endif