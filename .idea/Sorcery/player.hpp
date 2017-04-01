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
#include "spell.hpp"
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
    
    bool turn;
    int magic;
    string name;
    int health;
public:
    player(string name);
    ~player();
    
    ////////////////////////////////////////////
    void  setname(string inputname);
    const string getname();
    const int getmagic();
    const int gethealth();
    const int gethandamount();
    const int getbfamount();
    const int getgraveamount();
    const int getdeckamount();
    const vector<card*> gethand();
    const vector<minion*> getbattlefield();
    const vector<minion*> getgrave();
    const ritual* getritual();
    void changehealth(string how, int much);
    void changemagic(string how, int much);
    void add_magic();
    //BASIC INFORMATION//
    ///////////////////////////////////////////
    
    void draw();//draw ONE card from deck to hand if hand is not full
    
    void destroy_ritual();//remove exiting ritual from this game
    void summon(minion &other);//summon a minion from hand to battlefield
    
    void play(int i);//play a card,,,,,,,need to implement, also remember destroy some cards when using them. 
    
    void destroy_hand_card(card &other);//remove a card in your hand from this game
    void destroy(minion &other);//move a minion which is on the battlefield to grave or card Banish
    void bring_back(minion &other);//call when use card Summon
    void raise_dead();//call when use card RaiseDead
    void change_ritual_charge(string how, int much);//call when use car Recharge
    
    void aoe(string how, int much);//call when AOE(Blizzard) is used, deal same damage to all minions on the battle field
};



#endif
