#include "Face.h"

Face::Face(vector<double3 *> points) : p1(points[0]), p2(points[1]), p3(points[2]), storedBounds(
        p1->min(*p2).min(*p3), p1->max(*p2).max(*p3)
) {}

float Face::dist(double3 point) {
    double3 &lp1 = *p1;
    double3 &lp2 = *p2;
    double3 &lp3 = *p3;
    auto normal = (lp3 - lp1).cross(lp2 - lp1).norm();

    auto o1 = (point - lp1).dot((lp2 - lp1).cross(normal));
    auto o2 = (point - lp2).dot((lp3 - lp2).cross(normal));
    auto o3 = (point - lp3).dot((lp1 - lp3).cross(normal));

    //union of 3 half-spaces
    if (sign(o1) == sign(o2) && sign(o2) == sign(o3)) {
        return dist_point_plane(point, lp1, normal);
    } else {
        auto d1 = dist_point_sector(point, lp1, lp2);
        auto d2 = dist_point_sector(point, lp2, lp3);
        auto d3 = dist_point_sector(point, lp3, lp1);
        return min(min(d1, d2), d3);
    }
}

Box Face::bounds() {
    return this->storedBounds;
}
