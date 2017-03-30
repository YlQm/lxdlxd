#ifndef ENRAGE_HPP
#define ENRAGE_HPP

class enrage :public : enchantment

{
	string description;
public:
	enrage(card *card);
	~enrage();
	string getdescription();
	void useability();
};