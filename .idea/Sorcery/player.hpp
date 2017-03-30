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
#include "card.hpp"
#include "minion.hpp"
#include <vector>

using namespace std;

class player{
    vector<card*> hand;
    int handamount;
    vector<minion*> battlefield;
    int bfamount;
    vector<minion*> grave;
    int graveamount;
    vector<card*> deck;
    int deckamount;
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
    int gethandzmount();
    int getbfamount();
    int getgraveamount();
    int getdeckamount();
    void changehealth(string how, int much);
    void changemagic(string how, int much);
    void draw();
    void destroy(minion &other);
    void summon(minion &other);
};



#endif
