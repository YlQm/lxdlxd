#include <iostream>
#include "deck.hpp"
using namespace std;

deck::deck(): num{0}()

deck::~deck(){
	for (int i = 0; i < theDeck.size(); i ++){
		delete theDeck[i];
	}
	theDeck.clear();
}

void deck::addtodeck(string newcard, player *player1, player *player2){

	if (newcard == "Air elemental"){
		card *newcard = new AirElemental("Air Elemental", 1, "", player1, player2, "no ability minion", 0, 1, 1, 0, 0);
//	} else if (newcard == "Earth Elemental"){
//		card *newcard = new EarthElemental;
//	} else if (newcard == "Bone Golem"){
//		card *newcard = new BoneGolem;
//	} else if (newcard == "Fire Elemental"){
//		card *newcard = new FireElemental;
//	} else if (newcard == "Potion Seller"){
//		card *newcard = new PotionSeller;
//	} else if (newcard == "Novice Pyromancer"){
//		card *newcard = new NovicePyromancer;
//	} else if (newcard == "Apprentive Summoner"){
//		card *newcard = new ApprentiveSummoner;
//	} else if (newcard == "Master Summoner"){
//		card *newcard = new MasterSummoner;
//	} else if (newcard == "Banish"){
//		card *newcard = new Banish;
//	} else if (newcard == "Unsummon"){
//		card *newcard = new Unsummon;
//	} else if (newcard == "Recharge"){
//		card *newcard = new Recharge;
//	} else if (newcard == "Disenchant"){
//		card *newcard = new Disenchant;
//	} else if (newcard == "Raise Dead"){
//		card *newcard = new RaiseDead;
//	} else if (newcard == "Blizzard"){
//		card *newcard = new Blizzard;
//	} else if (newcard == "Giant Strength"){
//		card *newcard = new GiantStrength;
	//} else if (newcard == "Enrage"){
//		card *newcard = new Enrage;
	//} else if (newcard == "Haste"){
	//	card *newcard = new Haste;
//	} else if (newcard == "Magic Fatigue"){
//		card *newcard = new MagicFatigue;
	//} else if (newcard == "Silence"){
	//	card *newcard = new Silence;
//	} else if (newcard == ""){
//		card *newcard = new ;
//	} else if (newcard == ""){
//		card *newcard = new ;
//	}else if (newcard == ""){
//		card *newcard = new ;
//	}else if (newcard == ""){
//		card *newcard = new ;
	} else {
		card *newcard = new AirElemental;
	}
	thedeck.push_back(newcard);
}


void deck::shuffledeck(){
	random_shuffle(theDeck.begin(),theDeck.end());
}