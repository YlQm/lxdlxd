#include <iostream>
#include "deck.h"
using namespace std;

deck::deck(): num{0}()

deck::~deck(){
	theDeck.clear();
	realDeck.clear();
}

void deck::addtodeck(string newcard){
	thedeck.push_back(newcard);
}