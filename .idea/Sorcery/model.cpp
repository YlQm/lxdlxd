//
//  model.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-04-01.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "model.hpp"

model::model(player player1, player player2):player1{player1}, player2{player2}{}
model::~model(){};

const player& model::getplayer1(){return player1;}
const player& model::getplayer2(){return player2;}
const vector<card*> model::gethand1(){return player1.gethand();}
const vector<card*> model::gethand2(){return player2.gethand();}
const vector<minion*> model::getbattlefield1(){return player1.getbattlefield();}
const vector<minion*> model::getbattlefield2(){return player2.getbattlefield();}
const vector<minion*> model::getgrave1(){return player1.getgrave();}
const vector<minion*> model::getgrave2(){return player2.getgrave();}
const ritual* model::getplayer1ritual(){return player1.getritual();}
const ritual* model::getplayer2ritual(){return player2.getritual();}
