#ifndef AF_MATH_H
#define AF_MATH_H

#include "AF_Vec3.h"
#include "math.h"

#ifdef __cplusplus
extern "C" {
#endif


    // Two sides method and angle method
    static inline float area_of_triangle(const AF_Vec3 _v1, const AF_Vec3 _v2, const AF_Vec3 _v3)
    {
        return fabs((_v1.x * (_v2.y - _v3.y) + _v2.x * (_v3.y - _v1.y) + _v3.x * (_v1.y - _v2.y)) / 2.0f);
    }

#ifdef __cplusplus
}
#endif

#endif  // AF_MATH_H