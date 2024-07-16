#ifndef AF_MATH_H
#define AF_MATH_H

#include "AF_Vec3.h"
#include "AF_Mat4.h"
#include "math.h"

#ifdef __cplusplus
extern "C" {
#endif
#define AF_PI 3.14159265358979323846


static inline float AF_Math_Radians(float _degrees){
	return (_degrees * AF_PI) / 180.0f; 
}

// Two sides method and angle method
static inline float area_of_triangle(const AF_Vec3 _v1, const AF_Vec3 _v2, const AF_Vec3 _v3)
{
	return fabs((_v1.x * (_v2.y - _v3.y) + _v2.x * (_v3.y - _v1.y) + _v3.x * (_v1.y - _v2.y)) / 2.0f);
}

static inline AF_Mat4 AF_Math_Lookat(AF_Vec3 _target, AF_Vec3 _position, AF_Vec3 _up){
 	AF_Vec3 normZ = AFV3_NORMALIZE(AFV3_MINUS(_target, _position));
        AF_Vec3 xaxis = AFV3_NORMALIZE(AFV3_CROSS(normZ, _up));
        AF_Vec3 yaxis = AFV3_CROSS(xaxis, normZ);
        AF_Vec3 zaxis = {-normZ.x, -normZ.y, -normZ.z};

	AF_Vec4 row1 = {xaxis.x, yaxis.x, zaxis.x, 0.0f};
	AF_Vec4 row2 = {xaxis.y, yaxis.y, zaxis.y, 0.0f};
	AF_Vec4 row3 = {xaxis.z, yaxis.z, zaxis.z, 0.0f};

	float dotX = -AFV3_DOT(xaxis, _position);

	float dotY = -AFV3_DOT(yaxis, _position);

	float dotZ = -AFV3_DOT(zaxis, _position);

	AF_Vec4 row4 = {dotX, dotY, dotZ, 1};

	AF_Mat4 viewMatrix;
        viewMatrix.rows[0] = row1;
        viewMatrix.rows[1] = row2;
        viewMatrix.rows[2] = row3;
        viewMatrix.rows[3] = row4;
        return viewMatrix;
}


#ifdef __cplusplus
}
#endif

#endif  // AF_MATH_H
