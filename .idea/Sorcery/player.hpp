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
#include "ritual.hpp"
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
    ritual *r;
    bool ritual_exist;
    int magic;
    string name;
    int health;
public:
    player(string name);
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
    void add_magic();
    
    void draw();//draw cards
    
    void destroy_ritual();//remove exiting ritual from this game
    void summon(minion &other);//summon a minion from hand to battlefield
    
    void play(int i);//play a card,,,,,,,need to implement
    
    void destroy(minion &other);//move a minion which is on the battlefield to grave or card Banish
    void bring_back(minion &other);//call when use card Summon
    void raise_dead();//call when use card RaiseDead
    void change_ritual_charge(string how, int much);//call when use car Recharge
};



#endif
