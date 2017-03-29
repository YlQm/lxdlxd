#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include "model.h"
#include "hand.hpp"
#include "Battlefield.h"
#include "Grave.h"

using namespace std;

class player: public model
{
    hand *h;
    Battlefield *bf;
    Grave *g;
    int magic;
    string name;
    int health;
public:
    player();
    ~player();
    void  setname(string inputname);
    string getname();
    int getmagic();
    int gethealth();
    void changehealth(string how, int much);
    void changemagic(string how, int much);
    void behitted(minion &m);
};



#endif