//
//  deck.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-02.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef _DECK_HPP_
#define _DECK_HPP_
#include <string>
#include <vector>
#include "player.hpp"

using namespace std;

class deck
{
    vector<card*> theDeck;
public:
    deck();
    ~deck();
    void addtodeck(string newcard, player *player1, player *player2);
    void shuffledeck();
    vector<card *> getdeck();
};

#endif
