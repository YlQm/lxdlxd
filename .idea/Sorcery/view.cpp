
#include <string>
#include <iostream>
#include <vector>
#include "ascii_graphics.hpp"
#include "view.hpp"
#include "card.hpp"
#include "model.hpp"
#include "minion.hpp"
#include "spell.hpp"
#include "enchantment.cpp"
#include "ritual.hpp"
using namespace std;
view::view():model{NULL},top{line(CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY,PLAYER_1_TEMPLATE,CARD_TEMPLATE_EMPTY,CARD_TEMPLATE_EMPTY)},
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



card_template_t view::print_card(minion *m){
    string type = m->gettype();
    string cardname = m->getname();
    int cardcost = m->getcost();
    if (type == "no_ability_minion"){
        int minionattack = m->getattack();
        int miniondefence = m->getdefence();
        card_template_t newcard = display_minion_no_ability(cardname, cardcost, minionattack, miniondefence);
    }else if (type == "triggered_ability_minion"){
        int minionattack = m->getattack();
        int miniondefence = m->getdefence();
        string carddes = m->getdescription();
        card_template_t newcard = display_minion_triggered_ability(cardname, cardcost, minionattack, miniondefence, carddes);
    }else{
        int minionattack = m->getattack();
        int miniondefence = m->getdefence();
        string carddes = m->getdescription();
        int abilitycost = m->getablitycost();
        card_template_t newcard = display_minion_activated_ability(cardname, cardcost, minionattack, miniondefence, abilitycost, carddes);
    }
    return newcard;
}

card_template_t view::print_card(ritual *r){
    string cardname = r->getname();
    int cardcost = r->getcost();
    string carddes = r->getdescription();
    int cardcharge = r->getcharge();
    int ritualcost = r->getritualcost();
    card_template_t newcard = display_ritual(cardname, cardcost, ritualcost, carddes , cardcharge);
    return newcard;
}

card_template_t view::print_card(spell *s){
    string cardname = s->getname();
    int cardcost = s->getcost();
    string carddes = s->getdescription();
    card_template_t newcard = display_spell(cardname, cardcost, carddes);
    return newcard;
}

card_template_t view::print_card(enchantment *e){
    string type = e->gettype();
    string cardname = e->getname();
    int cardcost = e->getcost();
    if (type == "enchantment"){
        string carddes = e->getdescription();
        card_template_t newcard = display_enchantment(cardname, cardcost, carddes);
    }else {
        string carddes = e->getdescription();
        string enchantmentattack = e->getattack();
        string enchantmentdefence = e->getdefence();
        card_template_t newcard = display_enchantment_attack_defence(cardname, cardcost, carddes, enchantmentattack, enchantmentdefence);
    }
    return newcard;
}

void view::update(){
    int hand1 = model->player1.gethandamount();
    for (int i = 0; i < hand1; i++){
        player1_hand.changecard(print_card(model->gethand1()[i]), i);
    }
    if (hand1 < 5){
        int n = 5 - hand1;
        for (int i = 5; i > (5-n); i--){
            player1_hand.changecard(CARD_TEMPLATE_EMPTY, i);
        }
    }
    int hand2 = model->player2.gethandamount();
    for (int i = 0; i < hand1; i++){
        player2_hand.changecard(print_card(model->gethand2()[i]), i);
    }
    if (hand2 < 5){
        int n = 5 - hand1;
        for (int i = 5; i > (5-n); i--){
            player2_hand.changecard(CARD_TEMPLATE_EMPTY, i);
        }
    }
    int battlefield1 = model->player1.getbfamount();
    for (int i = 0; i < battlefield1; i++){
        player1_battlefield.changecard(print_card(model->getbattlefield1()[i]), i);
    }
    if (battlefield1 < 5){
        int n = 5 - battlefield1;
        for (int i = 5; i > (5-n); i--){
            player1_battlefield.changecard(CARD_TEMPLATE_EMPTY, i);
        }
    }
    int battlefield2 = model->player2.getbfamount();
    for (int i = 0; i < battlefield2; i++){
        player2_battlefield.changecard(print_card(model->getbattlefield2()[i]), i);
    }
    if (battlefield2 < 5){
        int n = 5 - battlefield2;
        for (int i = 5; i > (5-n); i--){
            player2_battlefield.changecard(CARD_TEMPLATE_EMPTY, i);
        }
    }
    
    if (model.getplayer1ritual()){
        top.changecard(print_card(model->getplayer1ritual()),1);
    }
    if (model.getplayer2ritual()){
        bottom.changecard(print_card(model->getplayer2ritual()),5);
    }
    if (model.getplayer1grave()){
        top.changecard(print_card(model->getplayer1grave()),1);
    }
    if (model.getplayer2grave()){
        bottom.changecard(print_card(model->getplayer2grave()),5);
    }
    
    updateplayer(model->getplayer1(),1);
    updateplayer(model->getplayer2(),2);
    print_view();
}

void view::updateplayer(player p, int i){//i represent this is player1 or player2
    string playername = p.getname();
    int playerhealth = p.gethealth();
    int playermana = p.getmana();
    card_template_t newcard = display_player_card(i, playername, playerhealth, playermana);
    if (i == 1){
        top.changecard(newcard, 3);
    }else {
        bottom.changecard(newcard, 3);
    }
}