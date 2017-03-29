//
//  Grave.cpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#include "grave.hpp"

grave::grave():amount{0}{}

grave::~grave(){
    realgrave.clear();
}
