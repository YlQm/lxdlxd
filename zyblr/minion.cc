#include "minion.h"

minion::minion() : name{""}, cost{0}, health{0}, attack{0}, action{0}{}

minion::~minion(){}

void minion::changeattack(string how, int much){
    if (how == "plus"){
        attack += much;
    } else {
        attack -= much;
    }
}

void minion::changehealth(string how, int much){
    if (how == "plus"){
        health += much;
    } else {
        health -= much;
    }
}
void minion::hit(){}
void minion::useability(){}