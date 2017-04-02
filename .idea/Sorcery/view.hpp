
#ifndef view_hpp
#define view_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ascii_graphics.hpp"
#include "line.hpp"
using namespace std;
class minion;
class ritual;
class spell;
class enchantment;
class card;
class model;

class view{
    model *mymodel;
    line top;
    line player1_battlefield;
    line player2_battlefield;
    line bottom;
    line player1_hand;
    line player2_hand;
public:
    view();
    ~view();
    void print_hand(const int i);
    void print_view();
    card_template_t print_card(const minion *m);
    card_template_t print_card(const ritual *r);
    card_template_t print_card(const spell *s);
    card_template_t print_card(const enchantment *e);
    card_template_t print_card(const card *c);
    void inspect(const nt i, const int n);
    void updateplayer(const player p, const int i);
    void update();
};
#endif