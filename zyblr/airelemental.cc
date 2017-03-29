#include "airelemental.h"
#include "player.h"

airelemental::airelemental():name{"airelemental"}attack{1}, health{1}, cost{1}{}

airelemental::~airelemental(){}

void hit(player &p){
	if (action = 1){
		p->health -= attack;
		action -= 1;
	} else{
		cout << "No action!" << endl;
	}
}