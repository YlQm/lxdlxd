#ifndef _DECK_H_
#define _DECK_H_
#include <string>
#include <vector>
using namespace std;

class deck
{
        vector<string> theDeck;
        vector<card> realDeck;
        int num;
public:
        deck();
        ~deck();
        void addtodeck(string newcard);
        void initdeck();
};

#endif