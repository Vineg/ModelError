#ifndef STRUCTS_H
#define STRUCTS_H

#include <cstdint>
#include <vector>

#include "double3.h"

using namespace std;

typedef	unsigned int uint;

struct uint3 { uint32_t x, y, z; };
struct uchar3 { uint8_t r, g, b; };
struct double3;

struct float3 {
    float x, y, z;
    float3 (double cx, double cy, double cz) : x(cx), y(cy), z(cz){};
    float3 (double3& d);
    float3 () : x(0), y(0), z(0) {}
};

struct geometry
{
    vector<double3> vertices;
    vector<uint3> faces;
    vector<uchar3> colors;
};

#endif //STRUCTS_H