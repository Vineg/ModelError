#ifndef MODELERROR_FACE_H
#define MODELERROR_FACE_H

#include <algorithm>

#include "double3.h"
#include "Box.h"
#include "Shape.h"
#include "utils.h"

struct Face : public Shape {
    double3* p1;
    double3* p2;
    double3* p3;
    Box storedBounds;
    explicit Face(vector<double3*> points);
    float dist(double3 point);
    Box bounds() override;
};


#endif //MODELERROR_FACE_H
