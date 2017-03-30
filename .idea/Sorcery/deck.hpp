//
//  deck.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp

#include <string>
#include <vector>
using namespace std;

class card;

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

#endif /* deck_hpp */
