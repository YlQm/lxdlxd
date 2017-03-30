//
//  Battlefield.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "battlefield.hpp"

battlefield::battlefield():amount{0}{}

battlefield::~battlefield(){
    realfield.clear();
}
