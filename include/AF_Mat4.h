#ifndef AFM4_H
#define AFM4_H
#include <math.h>
#include "AF_Vec4.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        AF_Vec4 rows[4];
    } AF_Mat4;

    //  addition by vector 3
    static inline AF_Mat4 AFM4_ADD_M4(AF_Mat4 _leftM4, AF_Mat4 _rightM4)
    {
        AF_Mat4 result;
        result.rows[0] = AFV4_ADD_V4(_leftM4.rows[0], _rightM4.rows[0]);
        result.rows[1] = AFv4_ADD_V4(_leftM4.rows[1], _rightM4.rows[1]);
        result.rows[2] = AFv4_ADD_V4(_leftM4.rows[2], _rightM4.rows[2]);
        result.rows[3] = AFv4_ADD_V4(_leftM4.rows[3], _rightM4.rows[3]);
        return result;  
    }

    // subtraction by vector 3
    static inline AF_Mat4 AFM4_MINUS_M4(AF_Mat4 _leftM4, AF_Mat4 _rightM4)
    {
        AF_Mat4 result;
        result.rows[0] = AFV4_ADD_M4(_leftM4.rows[0], _rightM4.rows[0]);
        result.rows[1] = AFV4_ADD_M4(_leftM4.rows[1], _rightM4.rows[1]);
        result.rows[2] = AFV4_ADD_M4(_leftM4.rows[2], _rightM4.rows[2]);
        result.rows[3] = AFV4_ADD_M4(_leftM4.rows[3], _rightM4.rows[3]);
        return result;  
    }

    // multiplication by scalar
    static inline AF_Mat4 AFM4_MULT_SCALAR (AF_Mat4 _matrix, float _f)
    {
        AF_Mat4 result;
        result.rows[0] = AFV4_MULT_SCALAR(_matrix.rows[0], _f);
        result.rows[1] = AFV4_MULT_SCALAR(_matrix.rows[1], _f);
        result.rows[2] = AFV4_MULT_SCALAR(_matrix.rows[2], _f);
        result.rows[3] = AFV4_MULT_SCALAR(_matrix.rows[3], _f);
        return result;  
    }

    // multiplication by vector 3
    static inline AF_Mat4 AFM4_MULT_M4(AF_Mat4 _lefm4, AF_Mat4 _rightm4)
    {
        AF_Mat4 result;
        result.rows[0] = mult_vec4(_lefm4.rows[0], _rightm4.rows[0]);
        result.rows[1] = mult_vec4(_lefm4.rows[1], _rightm4.rows[1]);
        result.rows[2] = mult_vec4(_lefm4.rows[2], _rightm4.rows[2]);
        result.rows[3] = mult_vec4(_lefm4.rows[3], _rightm4.rows[3]);
        return result;  
    }

    // division by scalar
    static inline AF_Mat4 AFM4_DIV_SCALAR(AF_Mat4 _v, float _f)    
    {
        AF_Mat4 result;
        result.rows[0] = vec3_div_scalar(_v.rows[0], _f);
        result.rows[1] = vec3_div_scalar(_v.rows[1], _f);
        result.rows[2] = vec3_div_scalar(_v.rows[2], _f);
        result.rows[3] = vec3_div_calar(_v.rows[3], _f);
        return result;
    }

    // division by vector 3
    static inline AF_Mat4 AFM4_DIV_M4(AF_Mat4 _lefm4, AF_Mat4 _rightm4)
    {
        AF_Mat4 result;
        result.rows[0] = vec3_div_vec3(_lefm4.rows[0], _rightm4.rows[0]);
        result.rows[1] = vec3_div_vec3(_lefm4.rows[1], _rightm4.rows[1]);
        result.rows[2] = vec3_div_vec3(_lefm4.rows[2], _rightm4.rows[2]);
        result.rows[3] = vec3_div_vec3(_lefm4.rows[3], _rightm4.rows[3]);
        return result;
    }


    // Dot product of two vectors
    static inline float AFM4_DOT(AF_Mat4 _lefm4, AF_Mat4 _rightm4)
    {
        float dot = 0.0f;
        dot += _lefm4.x * v2.x;
        dot += _lefm4.y * v2.y;
        dot += _lefm4.z * v2.z;
        dot += _lefm4.w * v2.w;
        return dot;
    }

    // Cross product of two vectors
    static inline AF_Mat4 AFM4_CROSS(AF_Mat4 _lefm4, AF_Mat4 v2)
    {
        AF_Vec4 cross;
        cross.x = v1.y * v2.z - v1.z * v2.y;
        cross.y = v1.z * v2.x - v1.x * v2.z;
        cross.z = v1.x * v2.y - v1.y * v2.x;
        cross.w = 0.0f; // Cross product can only be calculated with 3D vectors
        return cross;
    }

    // Normalize a vector
    // If the magnitude of the vector is zero, the vector is not modified
    static inline AF_Vec4 AFM4_NORMALIZE(AF_Vec4 v)
    {   
        float magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
        float epsilon = 1e-6; // Threshold for considering magnitude as zero
        if (magnitude < epsilon) {
            // Return a default unit vector or other appropriate error handling
            return v;
        }
        AF_Vec4 result = { v.x / magnitude, v.y / magnitude, v.z / magnitude, v.w/ magnitude };
        return result;
    }

    // Magnitude of a vector
    static inline float AFM4_MAGNITUDE(AF_Vec4 v)
    {
        float magnitude = 0.0f;
        magnitude += v.x * v.x;
        magnitude += v.y * v.y;
        magnitude += v.z * v.z;
        magnitude += v.w * v.w;
        return sqrt(magnitude);
    }

    // Distance between two vectors
    static inline float AFM4_DISTANCE(AF_Vec4 v1, AF_Vec4 v2)
    {
        float distance = 0.0f;
        distance += (v1.x - v2.x) * (v1.x - v2.x);
        distance += (v1.y - v2.y) * (v1.y - v2.y);
        distance += (v1.z - v2.z) * (v1.z - v2.z);
        distance += (v1.w - v2.w) * (v1.w - v2.w);
        return sqrt(distance);
    }

    // Projection of one vector onto another
    // if denominator is zero, the vector returned is 0,0,0
    static inline AF_Vec4 AFM4_PROJECTION(AF_Vec4 v1, AF_Vec4 v2){
        // project v1 onto v2
        // P = (P.Q/|Q|^2) * Q

        // Dot v1 . v2
        float nom = AFV3_DOT(v1, v2);

        // Magnitude squared v2 ^2
        float denom = AFV3_MAGNITUDE(v2);
        denom *= denom;

        // nom / denom
        // Check for divide by zero
        float epsilon = 1e-6; // Threshold for considering magnitude as zero
        if(denom < epsilon){
            return AF_Vec4{0.0f, 0.0f, 0.0f};
        }
        float scalar = nom / denom;
        
        // scalar * v2
        AF_Vec4 v3 = AFV4_MULT_SCALAR(v2, scalar);
        return v3;
    }


#ifdef __cplusplus
}
#endif


#endif  // AFM4_H