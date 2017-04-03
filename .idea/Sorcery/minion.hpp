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
    int activated_ability_cost;
public:
    minion(string name, int cost, string description, player *p1, player *p2, string type, int action, int defence, int attack, int buffamount,int activated_ability_cost);
    virtual ~minion();
    void change_defence(string how, int much);
    void change_attack(string how, int much);
    void changeaction(string how, int much);
    void hit(minion &other);
    void hit(player &other);
    void being_hit (int otherattack);
    void being_destroy();
    bool isdead();
    int getbfposiotion();
    void setbfposition(int newposition);
    void back_to_hand();
    void set_defence(int newdefence);
    void set_attack(int newattack);
    int getattack();
    int getdefence();
    int getabilitycost();
    
    const vector<enchantment*>& getbuff();
    int get_buff_amount();
    void get_enrage();
    void add_buff(enchantment &other);
    void get_strength();
    void destroy_top_enchantment();
    void silence(bool zyb);
    void add_action();
};

#endif /* minion_hpp */

