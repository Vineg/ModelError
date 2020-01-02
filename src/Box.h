#ifndef MODELERROR_BOX_H
#define MODELERROR_BOX_H


#include "Point.h"

class Box {
public:
    Point start;
    Point end;
    explicit Box(Box* toClone);
    Box(Point start, Point end);
    bool intersects(const Box& other);
    double maxWidth();
};


#endif //MODELERROR_BOX_H
