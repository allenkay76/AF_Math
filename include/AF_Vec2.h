#ifndef AF_VEC2_H
#define AF_VEC2_H
#include "AF_Lib_Define.h"
#include "AF_Math.h"
#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        AF_FLOAT x, y;
    } AF_Vec2;

    //  addition by vector 3
    static inline AF_Vec2 AFV2ADD(AF_Vec2 v1, AF_Vec2 v2)
    {
        AF_Vec2 result = {0,0};
        result.x = v1.x + v2.x;
        result.y = v1.y + v2.y;
        return result;  
    } 


    // subtraction by vector 3
    static inline AF_Vec2 AFV2_MINUS(AF_Vec2 v1, AF_Vec2 v2)
    {
        AF_Vec2 result = {0,0};
        result.x = v1.x - v2.x;
        result.y = v1.y - v2.y;
        return result;
    }

    // multiplication by scalar
    static inline AF_Vec2 AFV2_MULT_SCALAR(AF_Vec2 v, AF_FLOAT f)
    {
        AF_Vec2 result;
        result.x = v.x * f;
        result.y = v.y * f;
        return result;
    }

    // multiplication by vector 3
    static inline AF_Vec2 AFV2_MULT(AF_Vec2 v1, AF_Vec2 v2)
    {
        AF_Vec2 result;
        result.x = v1.x * v2.x;
        result.y = v1.y * v2.y;
        return result;
    }

    // division by scalar
    static inline AF_Vec2 AFV2_DIV_SCALAR(AF_Vec2 v, AF_FLOAT f)    
    {
        AF_Vec2 result;
        result.x = v.x / f;
        result.y = v.y / f;
        return result;
    }

    // division by vector 3
    static inline AF_Vec2 AFV2_DIV(AF_Vec2 v1, AF_Vec2 v2)
    {
        AF_Vec2 result;
        result.x = v1.x / v2.x;
        result.y = v1.y / v2.y;
        return result;
    }

    // Equality check
    static inline int AFV2_EQUAL(const AF_Vec2 v1, const AF_Vec2 v2){
        return (v1.x == v2.x && v1.y == v2.y);
    }

    // vec3_dot product of two vectors
    static inline AF_FLOAT AFV2_DOT(AF_Vec2 v1, AF_Vec2 v2)
    {
        AF_FLOAT _dot = 0;
        _dot += v1.x * v2.x;
        _dot += v1.y * v2.y;
        return _dot;
    }

    // Normalize a vector
    // If the magnitude of the vector is zero, the vector is not modified
    static inline AF_Vec2 AFV2_NORMALIZE(AF_Vec2 v)
    {   
        AF_FLOAT magnitude = AF_Math_Sqrt((AF_FLOAT)v.x * v.x + v.y * v.y);
        AF_FLOAT epsilon = AF_EPSILON; // Threshold for considering magnitude as zero
        if (magnitude < epsilon) {
            // Return a default unit vector or other appropriate error handling
            return v;
        }
        AF_Vec2 result = { v.x / magnitude, v.y};
	return result;
    }

    // Magnitude of a vector
    static inline AF_FLOAT AFV2_MAGNITUDE(AF_Vec2 v)
    {
        AF_FLOAT magnitude = 0;
        magnitude += v.x * v.x;
        magnitude += v.y * v.y;
        return AF_Math_Sqrt((AF_FLOAT)magnitude);
    }

    // Distance between two vectors

    static inline AF_FLOAT AFV2_DISTANCE(AF_Vec2 v1, AF_Vec2 v2)
    {
        AF_FLOAT distance = 0;
        distance += (v1.x - v2.x) * (v1.x - v2.x);
        distance += (v1.y - v2.y) * (v1.y - v2.y);
        return AF_Math_Sqrt((AF_FLOAT)distance);
    }
/*
====================
AFV2_ROTATE_TWARDS
Function for calculating a rotation angle value between two 2d point
====================
*/
	static inline AF_FLOAT AFV2_ROTATE_TOWARDS(AF_Vec2 _pos1, AF_Vec2 _pos2){
		// Rotate towards pos2
		AF_FLOAT rotDistX = (_pos1.x - _pos2.x);
		AF_FLOAT rotDistY = (_pos1.y - _pos2.y);
		AF_FLOAT lookatAngle = AF_Math_Atan2(rotDistX, rotDistY);
		return lookatAngle;
	}

#ifdef __cplusplus
}
#endif


#endif  // AF_VEC2_H
