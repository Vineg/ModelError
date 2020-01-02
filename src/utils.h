#ifndef MODELERROR_UTILS_H
#define MODELERROR_UTILS_H

#include <cmath>
#include "double3.h"
#include "structs.h"

inline double sign(double a) {
    return a >= 0 ? 1.0 : -1.0;
}

inline double step (double v) {
    return v > 0 ? 1 : 0;
}

inline float smooth_step(double v) {
    return step(v) * v - step(v - 1) * (v - 1);
}

inline float pike (double v) {
    return smooth_step(v) - smooth_step(v - 1);
}

inline uchar3 jet_color(double v) {
    v *= 4.0;
    return uchar3 {
            (uint8_t)(255u * (pike(v - 1.5) + pike(v - 2.5))),
            (uint8_t)(255u * (pike(v - 0.5) + pike(v - 1.5))),
            (uint8_t)(255u * (pike(v + 0.5) + pike(v - 0.5)))
    };
}

#endif //MODELERROR_UTILS_H
