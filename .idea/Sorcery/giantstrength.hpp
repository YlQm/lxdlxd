#ifndef GIANTSTRENGTH_HPP
#define GIANTSTRENGTH_HPP

class giantstrength :public : enchantment
{
	string description;
public:
	giantstrength(card *card);
	~giantstrength();	
	string getdescription();
	void useability();
};