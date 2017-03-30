//
//  Raise Dead.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Raise Dead.hpp"

RaiseDead::RaiseDead() :name{"RaiseDead"},cost{1},description{"Resurrect the top minion in your graveyard and set its defence to 1"}{}
RaiseDead::~RaiseDead(){}

string RaiseDead::getdescription(){
    return description;
}

void RaiseDead::raisedead(){}
