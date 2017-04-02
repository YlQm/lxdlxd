//
//  line.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef line_hpp
#define line_hpp

#include <string>
#include <iostream>
#include <vector>
#include "ascii_graphics.hpp"
using namespace std;

class line
{
    card_template_t card1;
    card_template_t card2;
    card_template_t card3;
    card_template_t card4;
    card_template_t card5;
public:
    line(card_template_t c1,card_template_t c2,card_template_t c3,card_template_t c4,card_template_t c5);
    ~line();
    friend ostream &operator<<(ostream &out, const line &l);
    void changecard(card_template_t c, int i);
    void clearline();
    void removecard(int i);
};

#endif /* line_hpp */
