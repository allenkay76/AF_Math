#ifndef AF_MATH_H
#define AF_MATH_H
#include "AF_Lib_Define.h"
//#include "AF_Log.h"
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_FIXED
static inline AF_FLOAT AF_Math_Sqrt(AF_FLOAT _value){
       printf("AF_Math_Sqrt: TODO\n");
	
	AF_FLOAT returnValue = _value*_value/_value;	
    return returnValue;
}
// TODO
static inline AF_FLOAT AF_Math_Atan2(AF_FLOAT _value1, AF_FLOAT _value2){
    printf("AF_Math_Atan2: TODO\n");	
    return _value1 + _value2;
}
// TODO
static inline AF_FLOAT AF_Math_Tan(AF_FLOAT _value1){
    printf("AF_Math_Tan: TODO\n");	
    return _value1 + _value1;
}

// TODO: 
static inline AF_FLOAT AF_Math_Sin(AF_FLOAT _value){
    printf("AF_Math_Sin: TODO\n");
    return _value + _value;
}

// TODO:
static inline AF_FLOAT AF_Math_Cos(AF_FLOAT _value){
    printf("AF_Math_Cos: TODO\n");
    return _value+_value;
}
// TODO:
static inline AF_FLOAT AF_Math_Radians(AF_FLOAT _degrees){
    printf("AF_Math_Radians: TODO \n");
    return _degrees+_degrees; 
}


#elif USE_FLOAT
#include "AF_Vec3.h"
#include "AF_Mat4.h"


#define AF_PI 3.14159265358979323846

#include "math.h"

static inline AF_FLOAT AF_Math_Sqrt(AF_FLOAT _value){
	return sqrt(_value);
}

static inline AF_FLOAT AF_Math_Atan2(AF_FLOAT _value1, AF_FLOAT _value2){
	return atan2(_value);
}

static inline AF_FLOAT AF_Math_Tan(AF_FLOAT _value1){
    return tan(_value1);
}

static inline AF_FLOAT AF_Math_Sin(AF_FLOAT _value){
    return sin(_value);
}

static inline AF_FLOAT AF_Math_Sin(AF_FLOAT _value){
    return cos(_value);
}

static inline AF_Float AF_Math_Radians(AF_FLOAT _degrees){
	return (_degrees * AF_PI) / 180; 
}

// Two sides method and angle method
static inline AF_FLOAT area_of_triangle(const AF_Vec3 _v1, const AF_Vec3 _v2, const AF_Vec3 _v3)
{
	return fabs((_v1.x * (_v2.y - _v3.y) + _v2.x * (_v3.y - _v1.y) + _v3.x * (_v1.y - _v2.y)) / 2);
}

static inline AF_Mat4 AF_Math_Lookat(AF_Vec3 _target, AF_Vec3 _position, AF_Vec3 _up){
 	AF_Vec3 normZ = AFV3_NORMALIZE(AFV3_MINUS(_target, _position));
        AF_Vec3 xaxis = AFV3_NORMALIZE(AFV3_CROSS(normZ, _up));
        AF_Vec3 yaxis = AFV3_CROSS(xaxis, normZ);
        AF_Vec3 zaxis = {-normZ.x, -normZ.y, -normZ.z};

	AF_Vec4 row1 = {xaxis.x, yaxis.x, zaxis.x, 0};
	AF_Vec4 row2 = {xaxis.y, yaxis.y, zaxis.y, 0};
	AF_Vec4 row3 = {xaxis.z, yaxis.z, zaxis.z, 0};

	AF_Float dotX = -AFV3_DOT(xaxis, _position);

	AF_Float dotY = -AFV3_DOT(yaxis, _position);

	AF_Float dotZ = -AFV3_DOT(zaxis, _position);

	AF_Vec4 row4 = {dotX, dotY, dotZ, 1};

	AF_Mat4 viewMatrix;
        viewMatrix.rows[0] = row1;
        viewMatrix.rows[1] = row2;
        viewMatrix.rows[2] = row3;
        viewMatrix.rows[3] = row4;
        return viewMatrix;
}
#endif

#ifdef __cplusplus
}
#endif

#endif  // AF_MATH_H
