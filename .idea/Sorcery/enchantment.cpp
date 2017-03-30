
#include "enchantment.hpp"

enchantment::enchantment(card *card) : name{""}, cost{0},card{card}{}

enchantment::~enchantment(){
	delete card;
}

void enchantment::useability(){}