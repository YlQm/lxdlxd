#include <string>
#include <iostream>
#include <vector>
#include "ascii_graphics.hpp"
#include "line.hpp"

line::line(card_template_t c1,card_template_t c2,card_template_t c3,card_template_t c4,card_template_t c5):card1{c1},card2{c2},card3{c3},card4{c4},card5{c5}{}

line::~line(){
	card1.clear();
	card2.clear();
	card3.clear();
	card4.clear();
	card5.clear();
}

void line::clearline(){
	card1.clear();
	card2.clear();
	card3.clear();
	card4.clear();
	card5.clear();
}

ostream &operator<<(ostream &out, const line &l){
	for (int i = 0; i <= 10 ;i++){
		out << EXTERNAL_BORDER_CHAR_UP_DOWN;
		out << l.card1[i];
		out << l.card2[i];
		out << l.card3[i];
		out << l.card4[i];
		out << l.card5[i];
		out << EXTERNAL_BORDER_CHAR_UP_DOWN << endl;
	}
	return out;
}


void line::changecard(card_template_t c, int i){
	if (i == 0){
		card1 = c;
	} else if (i == 1){
		card2 = c;
	} else if (i == 2){
		card3 = c;
	} else if (i == 3){
		card4 = c;
	} else {
		card5 = c;
	}
}

void line::removecard(int i){
	if (i == 0){
		card1 = card2;
		card2 = card3;
		card3 = card4;
		card4 = card5;
		card5 = CARD_TEMPLATE_EMPTY;
	} else if (i == 1){
		card2 = card3;
		card3 = card4;
		card4 = card5;
		card5 = CARD_TEMPLATE_EMPTY;
	} else if (i == 2){
		card3 = card4;
		card4 = card5;
		card5 = CARD_TEMPLATE_EMPTY;
	} else if (i == 3){
		card4 = card5;
		card5 = CARD_TEMPLATE_EMPTY;
	} else {
		card5 = CARD_TEMPLATE_EMPTY;
	}
}