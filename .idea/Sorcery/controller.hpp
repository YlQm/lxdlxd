//
//  controller.hpp
//  Sorcery
//
//  Created by 刘然 on 2017-03-28.
//  Copyright © 2017 刘然. All rights reserved.
//

#ifndef controller_hpp
#define controller_hpp

#include <stdio.h>
#include "model.hpp"
#include "view.hpp"

class controller{
    model *m;
    view *v;
public:
    controller();
    ~controller();
    void run(bool test);
};

#endif /* controller_hpp */
