#include "enrage.hpp"
#include <string>

enrage::enrage(card *card):enchantment(card), description{""}{}

enrage::~enrage(){
	delete card;
}

string enrage::getdescription(){
	return description;
}

enrage::useability(){
	int h = card->gethealth();
	int a = card->getattack();
	card->changehealth("plus", h);
	card->changeattack("plus", h);
	cout<<"enrage is used" <<endl;
}