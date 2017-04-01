//
//  model.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef model_hpp
#define model_hpp

#include <iostream>
#include "player.hpp"
#include <vector>
using namespace std;

class model{
    player player1;
    player player2;
public:
    model(player player1, player player2);
    ~model();
    const player& getplayer1();
    const player& getplayer2();
    const vector<card*> gethand1();
    const vector<card*> gethand2();
    const vector<minion*> getbattlefield1();
    const vector<minion*> getbattlefield2();
    const vector<minion*> getgrave1();
    const vector<minion*> getgrave2();
    const ritual* getplayer1ritual();
    const ritual* getplayer2ritual();
};

#endif
