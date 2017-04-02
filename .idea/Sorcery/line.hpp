#ifndef _line_H_
#define _line_H_
#include <string>
#include <iostream>
#include <vector>
#include "ascii_graphics.h"
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
	void clearline(line l);
	void removecard(int i);
};
#endif