#include <iostream>
#include "player.h"
using namespace std;

player::player() : magic{0}, name{""}, health{20}{}

player::~player(){}

string player::getname(){
        return name;
}

int player::getmagic(){
        return magic;
}

int player::gethealth(){
        return health;
}

void player::setname(string inputname){
        name = inputname;
}

void behitted(minion &m){
	m.hit(*this);
}
