#include "giantstrength.hpp"
#include <string>

giantstrength::giantstrength(card *card):enchantment(card), description{""}{}

giantstrength::~giantstrength(){
	delete card;
}

string giantstrength::getdescription(){
	return description;
}

void giantstrength::useability(){
	card->changehealth("plus", 2);
	card->changeattack("plus", 2);
	cout<<"giantstrength is used" <<endl;
}