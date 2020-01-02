#ifndef MODELERROR_SHAPE_H
#define MODELERROR_SHAPE_H


#include "Box.h"

class Shape {
public:
    virtual Box bounds() = 0;
};


#endif //MODELERROR_SHAPE_H
