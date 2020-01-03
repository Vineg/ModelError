#ifndef MODELERROR_POINT_H
#define MODELERROR_POINT_H

#include <vector>

#include "tinyply.h"
#include "structs.h"
#include "double3.h"

using namespace std;

class Point : public vector<double> {
    using vector<double>::vector;
public:
    Point();
    Point(double3 data);
    Point(size_type size);
    Point(initializer_list<double> d);

    Point nthCombination(uint n, Point other);
    uint totalCombinations();
    Point add(Point other);
    Point scl(double scale);
};

#endif //MODELERROR_POINT_H
