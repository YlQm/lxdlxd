//
//  view.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#include <string>
#include <iostream>
#include <vector>
#include "ascii_graphics.hpp"
#include "view.hpp"
#include "card.hpp"
#include "minion.hpp"
#include "spell.hpp"
#include "enchantment.cpp"
#include "ritual.hpp"
using namespace std;

view::view():mymodel{NULL},top{line(CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,PLAYER_1_TEMPLATE,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY)},
player1_battlefield{line(CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY)},
player2_battlefield{line(CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY)},
bottom{line(CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,PLAYER_2_TEMPLATE,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY)},
player1_hand{line(CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,PLAYER_2_TEMPLATE,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY)},
player2_hand{line(CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,PLAYER_2_TEMPLATE,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY)}{}


view::~view(){
    top.clearline();
    player1_battlefield.clearline();
    player2_battlefield.clearline();
    bottom.clearline();
    player1_hand.clearline();
    player2_hand.clearline();
}

void view::print_hand( int i){ // i represent which player is active
    if (i == 1){
        cout << player1_hand;
    } else{
        cout << player2_hand;
    }
    
}


void view::print_view(){
    cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (int i = 0; i <=164; i ++){
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT<<endl;
    
    cout << top;
    cout << player1_battlefield;
    card_template_t v3 = CENTRE_GRAPHIC;
    for (auto it = v3.begin(); it != v3.end(); it ++){
        cout << *it <<endl;
    }
    cout << player2_battlefield;
    cout << bottom;
    
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for (int i = 0; i <=164; i ++){
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT<<endl;
}



card_template_t view::print_card( minion *m){
    string type = m->gettype();
    string cardname = m->getname();
    int cardcost = m->getcost();
    if (type == "no ability minion"){
        int minionattack = m->getattack();
        int miniondefence = m->getdefence();
        card_template_t newcard = display_minion_no_ability(cardname, cardcost, minionattack, miniondefence);
        return newcard;
    }else if (type == "triggered ability minion"){
        int minionattack = m->getattack();
        int miniondefence = m->getdefence();
        string carddes = m->getdescription();
        card_template_t newcard = display_minion_triggered_ability(cardname, cardcost, minionattack, miniondefence, carddes);
        return newcard;
    }else{
        int minionattack = m->getattack();
        int miniondefence = m->getdefence();
        string carddes = m->getdescription();
        int abilitycost = m->getabilitycost();
        card_template_t newcard = display_minion_activated_ability(cardname, cardcost, minionattack, miniondefence, abilitycost, carddes);
        return newcard;
    }
    
}

card_template_t view::print_card( ritual *r){
    string cardname = r->getname();
    int cardcost = r->getcost();
    string carddes = r->getdescription();
    int cardcharge = r->getcharge();
    int ritualcost = r->getritualcost();
    card_template_t newcard = display_ritual(cardname, cardcost, ritualcost, carddes , cardcharge);
    return newcard;
}

card_template_t view::print_card( spell *s){
    string cardname = s->getname();
    int cardcost = s->getcost();
    string carddes = s->getdescription();
    card_template_t newcard = display_spell(cardname, cardcost, carddes);
    return newcard;
}

card_template_t view::print_card( enchantment *e){
    string type = e->gettype();
    string cardname = e->getname();
    int cardcost = e->getcost();
    if (type == "enchantment"){
        string carddes = e->getdescription();
        card_template_t newcard = display_enchantment(cardname, cardcost, carddes);
        return newcard;
    }else {
        string carddes = e->getdescription();
        string enchantmentattack = e->getattack();
        string enchantmentdefence = e->getdefence();
        card_template_t newcard = display_enchantment_attack_defence(cardname, cardcost, carddes, enchantmentattack, enchantmentdefence);
        return newcard;
    }
}

card_template_t view::print_card( card *c){
    string type = c->gettype();
    if (type == "no ability minion" || type == "triggered ability minion" || type == "activated ability minion"){
        minion *m = dynamic_cast<minion*>(c);
        if (m){
            return print_card(m);
        } else {
            cout<<"bad casting in view"<<endl;
            return CARD_TEMPLATE_EMPTY;
        }
    } else if (type == "target spell" || type == "non-target spell"){
        spell *s = dynamic_cast<spell*>(c);
        if (s){
            return print_card(s);
        } else {
            cout<<"bad casting in view"<<endl;
            return CARD_TEMPLATE_EMPTY;
        }
    } else if (type == "ritual"){
        ritual *r = dynamic_cast<ritual*>(c);
        if (r){
            return print_card(r);
        } else {
            cout<<"bad casting in view"<<endl;
            return CARD_TEMPLATE_EMPTY;
        }
    } else{
        enchantment *e = dynamic_cast<enchantment*>(c);
        if (e){
            return print_card(e);
        } else {
            cout<<"bad casting in view"<<endl;
            return CARD_TEMPLATE_EMPTY;
        }
    }
}

void view::inspect( int i,  int n){ // i represent which player is active and n is the position of the minion
    if (i == 1){
        minion *m = mymodel->getbattlefield1()[n];
        int numofbuff = m->getbuff().size();
        line buffline = line(print_card(m),CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY);
        cout << buffline;
        while(numofbuff > 5){
            for (int i = 0; i < 5; i++){
                buffline.changecard(print_card(m->getbuff()[i]), i);
            }
            numofbuff -= 5;
            
            cout << buffline;
        }
        line emptyline = line(CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY);
        for (int j = 0; j < numofbuff; j++){
            emptyline.changecard(print_card(m->getbuff()[j]), j);
        }
        cout << buffline;
    } else{
        minion *m = mymodel->getbattlefield2()[n];
        int numofbuff = m->getbuff().size();
        line buffline = line(print_card(m),CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY);
        cout << buffline;
        while(numofbuff > 5){
            for (int i = 0; i < 5; i++){
                buffline.changecard(print_card(m->getbuff()[i]), i);
            }
            numofbuff -= 5;
            
            cout << buffline;
        }
        line emptyline = line(CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY);
        for (int j = 0; j < numofbuff; j++){
            emptyline.changecard(print_card(m->getbuff()[j]), j);
        }
        cout << buffline;
    }
}


void view::updateplayer( player p,  int i){//i represent this is player1 or player2
    string playername = p.getname();
    int playerhealth = p.gethealth();
    int playermana = p.getmagic();
    card_template_t newcard = display_player_card(i, playername, playerhealth, playermana);
    if (i == 1){
        top.changecard(newcard, 3);
    }else {
        bottom.changecard(newcard, 3);
    }
}


void view::update(){
    int hand1 = mymodel->gethand1().size();
    for (int i = 0; i < hand1; i++){
        player1_hand.changecard(print_card(mymodel->gethand1()[i]), i);
    }
    if (hand1 < 5){
        int n = 5 - hand1;
        for (int i = 5; i > (5-n); i--){
            player1_hand.changecard(CARD_TEMPLATE_EMPTY, i);
        }
    }
    int hand2 = mymodel->gethand2().size();
    for (int i = 0; i < hand1; i++){
        player2_hand.changecard(print_card(mymodel->gethand2()[i]), i);
    }
    if (hand2 < 5){
        int n = 5 - hand1;
        for (int i = 5; i > (5-n); i--){
            player2_hand.changecard(CARD_TEMPLATE_EMPTY, i);
        }
    }
    int battlefield1 = mymodel->getbattlefield1().size();
    for (int i = 0; i < battlefield1; i++){
        player1_battlefield.changecard(print_card(mymodel->getbattlefield1()[i]), i);
    }
    if (battlefield1 < 5){
        int n = 5 - battlefield1;
        for (int i = 5; i > (5-n); i--){
            player1_battlefield.changecard(CARD_TEMPLATE_EMPTY, i);
        }
    }
    int battlefield2 = mymodel->getbattlefield2().size();
    for (int i = 0; i < battlefield2; i++){
        player2_battlefield.changecard(print_card(mymodel->getbattlefield2()[i]), i);
    }
    if (battlefield2 < 5){
        int n = 5 - battlefield2;
        for (int i = 5; i > (5-n); i--){
            player2_battlefield.changecard(CARD_TEMPLATE_EMPTY, i);
        }
    }
    
    if (mymodel->getritual1()){
        top.changecard(print_card(mymodel->getritual1()),1);
    }
    if (mymodel->getritual2()){
        bottom.changecard(print_card(mymodel->getritual2()),1);
    }
    int i = mymodel->getgrave1().size();
    if (mymodel->getgrave1()[i]){
        top.changecard(print_card(mymodel->getgrave1()[i]),5);
    }
    int j = mymodel->getgrave2().size();
    if (mymodel->getgrave2()[j]){
        bottom.changecard(print_card(mymodel->getgrave2()[j]),5);
    }
    
    updateplayer(mymodel->getplayer1(),1);
    updateplayer(mymodel->getplayer2(),2);
    print_view();
}
