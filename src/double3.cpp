#include <algorithm>
#include <cmath>

#include "double3.h"

double3::double3(float3& f) {
    x = f.x;
    y = f.y;
    z = f.z;
}

double3 double3::operator + (const double3 right) {
    return double3{x + right.x, y + right.y, z + right.z};
}

double3 double3::operator - (const double3 right) {
    return double3{x - right.x, y - right.y, z - right.z};
}

double3 double3::operator * (const double right) {
    return double3{x * right, y * right, z * right};
}

double3 double3::min(double3 right) {
    return double3{
            std::min(x, right.x),
            std::min(y, right.y),
            std::min(z, right.z)
    };
}

double3 double3::max(double3 right) {
    return double3{
            std::max(x, right.x),
            std::max(y, right.y),
            std::max(z, right.z)
    };
}

double3 double3::cross(double3 right) {
    return double3{
            y * right.z - z * right.y,
            z * right.x - x * right.z,
            x * right.y - y * right.x
    };
}

double double3::dot(double3 right) {
    return x * right.x + y * right.y + z * right.z;
}

double3 double3::norm() {
    double l = length();
    return double3{x / l, y / l, z / l};
}

double double3::length() {
    return std::sqrt(length_sq());
}

double double3::length_sq() {
    return dot(*this);
}

double dist_point_plane(double3 point, double3 start, double3 normal) {
    return std::abs((point - start).dot(normal));
}

double dist_point_sector(double3 point, double3 p1, double3 p2) {
    double3 dif = p2 - p1;
    double p1Pos = p1.dot(dif);
    double p2Pos = p2.dot(dif);
    double pointPos = point.dot(dif);
    if (pointPos < p1Pos) {
        return (point - p1).length();
    }
    if (pointPos > p2Pos) {
        return (point - p2).length();
    }
    return (point - p1).cross(dif.norm()).length();
}
