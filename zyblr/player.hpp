//
//  player.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include "model.hpp"
#include "hand.hpp"
#include "Battlefield.hpp"
#include "Grave.hpp"

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
};



#endif
