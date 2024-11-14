#ifndef INIT_ABSTRACT_H
#define INIT_ABSTRACT_H

#include "init_returnType.h"

class InitAbstract {
private:
    /****** attributes ******/

public:
    /********* constructor ********/
    InitAbstract() {}

    /********** fundemental functions ***********/
    virtual INIT_ReturnType try_init() = 0;
};

#endif