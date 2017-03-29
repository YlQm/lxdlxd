//
//  Grave.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "Grave.hpp"

Grave::Grave():amount{0}{}

Grave::~Grave(){
    realgrave.clear();
}
