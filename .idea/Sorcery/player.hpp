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
#include "enchantment.hpp"
#include "ritual.hpp"
#include <vector>

using namespace std;

class player{
    vector<card*> hand;
    
    vector<minion*> battlefield;
    
    vector<minion*> grave;
    
    vector<card*> deck;
    
    ritual *r;
    bool ritual_exist;
    
    bool turn;
    int magic;
    int max_magic;
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
    const vector<card*> gethand();
    const vector<minion*> getbattlefield();
    const vector<minion*> getgrave();
    ritual* getritual();
    void changehealth(string how, int much);
    void changemagic(string how, int much);
    void add_magic();
    void setdeck(vector<card*> newdeck);
    //BASIC INFORMATION//
    ///////////////////////////////////////////
    
    
    void draw();//draw ONE card from deck to hand if hand is not full
    void attack(int i);//use ith minion to attack his face
    void attack(int i, int j);//use ith minion to attack his jth minion
    void reorder_hand();//call when need to order cards in your hand
    void destroy_ritual();//remove exiting ritual from this game
    void summon(minion &other);//summon a minion from hand to battlefield
    
    void play(int i);//play a card from hand without target
    void play(int i, string whichplayer, int j);//play a card from hand with target
    
    void add_max_magic();//add one max_magic
    void reset_action();//reset minion's action to 1 when your turn starts
    void reset_magic();//reset player's magic
    void discard(int i);//for test mod, remove a card from your hand: it will never appear in this game.
    void destroy_hand_card(card &other);//remove a card from your hand but not delete
    void destroy(minion &other);//move a minion which is on the battlefield to grave or card Banish
    void bring_back(minion &other);//call when use card Summon
    void raise_dead();//call when use card RaiseDead
    void change_ritual_charge(string how, int much);//call when use car Recharge
    void reorder_battlefield();//reorder minions' beposition
    
    void aoe(string how, int much);//call when AOE(Blizzard) is used, deal same damage to all minions on the battle field
    
};



#endif
