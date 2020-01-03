#include <vector>
#include "Point.h"

using namespace std;

Point::Point() : vector<double>() {
}

Point::Point(double3 data) : vector<double>({data.x, data.y, data.z}) {
}

Point::Point(size_type size) : vector<double>(size) {
}

Point::Point(initializer_list<double> d) : vector<double>(d) {
}

Point Point::nthCombination(uint n, Point other) {
    Point result = Point(size());
    for (uint i = 0; i < size(); i++) {
        if ((n & (1u << i)) == 0) {
            result[i] = (*this)[i];
        } else {
            result[i] = other[i];
        }
    }
    return result;
}

uint Point::totalCombinations() {
    return 1u << size();
}

Point Point::add(Point other) {
    Point result = Point(size());
    for (int i = 0; i < size(); i++) {
        result[i] = (*this)[i] + other[i];
    }
    return result;
}

Point Point::scl(double scale) {
    Point result = Point(size());
    for (int i = 0; i < size(); i++) {
        result[i] = (*this)[i] * scale;
    }
    return result;
}
