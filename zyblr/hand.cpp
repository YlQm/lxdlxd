//
//  hand.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-27.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "hand.hpp"

hand::hand():amount{0}{}

hand::~hand(){
    realhand.clear();
}

bool hand::checkfull(){
    return amount >= maxhandcard;
}
