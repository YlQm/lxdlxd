//
//  minion.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef minion_hpp
#define minion_hpp

#include <iostream>
#include "card.hpp"
#include <vector>

class enchantment;
class minion: public card{
    int action;
    int defence;
    int attack;
    int bfposition;
    vector<enchantment*> buff;
    int buffamount;
    bool acability = true;
public:
    minion(string name, int cost, string description, player *p1, player *p2, string type, int action, int defence, int attack, int buffamount);
    virtual ~minion();
    virtual void changedefence(string how, int much);
    virtual void changeattack(string how, int much);
    virtual void changeaction(string how, int much);
    virtual void hit(minion &other);
    virtual void hit(player &other);
    virtual void being_hit (int otherattack);
    virtual void being_destroy();
    virtual bool isdead();
    virtual int getbfposiotion();
    virtual void setbfposition(int newposition);
    virtual void back_to_hand();
    virtual void set_defence(int newdefence);
    virtual void set_attack(int newattack);
    
    virtual const vector<enchantment*>& getbuff();
    virtual int get_buff_amount();
    virtual void get_enrage();
    virtual void add_buff(enchantment &other);
    virtual void get_strength();
    virtual void destroy_top_enchantment();
    virtual void silence(bool zyb);
    virtual void add_action();
};

#endif /* minion_hpp */

