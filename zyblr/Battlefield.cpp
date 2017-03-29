//
//  Battlefield.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Battlefield.hpp"

Battlefield::Battlefield():amount{0}{}

Battlefield::~Battlefield(){
    realfield.clear();
}
