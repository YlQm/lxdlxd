#ifndef _VIEW_H_
#define _VIEW_H_
#include <string>
#include <iostream>
#include <vector>
#include "ascii_graphics.h"
using namespace std;

class line;
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
	void init_view();
	void print_view();

}
#endif