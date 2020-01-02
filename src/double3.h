#ifndef MODELERROR_DOUBLE3_H
#define MODELERROR_DOUBLE3_H

#include <vector>
#include "structs.h"
struct float3;

struct double3 {
    double x, y, z;

    double3 (double x, double y, double z): x(x), y(y), z(z){};
    double3 (float3& f);

    double3 operator + (const double3 right);
    double3 operator - (const double3 right);
    double3 operator * (const double right);

    double length_sq();
    double length();
    double3 norm();
    double dot(double3 right);
    double3 cross(double3 right);
    double3 min(double3 right);
    double3 max(double3 right);
};

double dist_point_sector(double3 point, double3 p1, double3 p2);

double dist_point_plane(double3 point, double3 start, double3 normal);

#endif //MODELERROR_DOUBLE3_H
