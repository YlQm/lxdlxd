#ifndef _DECK_HPP_
#define _DECK_HPP_
#include <string>
#include <vector>
using namespace std;

class deck
{
        vector<card*> theDeck;
        int num;
public:
        deck();
        ~deck();
        void addtodeck(string newcard, player *player1, player *player2);
        void shuffledeck();
};

#endif