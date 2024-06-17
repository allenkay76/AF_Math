#ifndef AF_VEC4_H
#define AF_VEC4_H
#include <math.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        float x, y, z, w;
    } AF_Vec4;


    //  addition by vector 3
    static inline AF_Vec4 AFV4_ADD(AF_Vec4 v1, AF_Vec4 v2)
    {
        AF_Vec4 result;
        result.x = v1.x + v2.x;
        result.y = v1.y + v2.y;
        result.z = v1.z + v2.z;
        result.w = v1.w + v2.w;
        return result;  
    } 

    


    // subtraction by vector 3
    static inline AF_Vec4 AFV4_MINUS(AF_Vec4 v1, AF_Vec4 v2)
    {
        AF_Vec4 result;
        result.x = v1.x - v2.x;
        result.y = v1.y - v2.y;
        result.z = v1.z - v2.z;
        result.w = v1.w - v2.w;
        return result;
    }

    // multiplication by scalar
    static inline AF_Vec4 AFV4_MULT_SCALAR(AF_Vec4 v, float f)
    {
        AF_Vec4 result;
        result.x = v.x * f;
        result.y = v.y * f;
        result.z = v.z * f;
        result.w = v.w * f;
        return result;
    }

    // multiplication by vector 3
    static inline AF_Vec4 AFV4_MULT(AF_Vec4 v1, AF_Vec4 v2)
    {
        AF_Vec4 result;
        result.x = v1.x * v2.x;
        result.y = v1.y * v2.y;
        result.z = v1.z * v2.z;
        result.w = v1.w * v2.w;
        return result;
    }

    // division by scalar
    static inline AF_Vec4 AFV4_DIV_SCALAR(AF_Vec4 v, float f)    
    {
        AF_Vec4 result;
        result.x = v.x / f;
        result.y = v.y / f;
        result.z = v.z / f;
        result.w = v.w / f;
        return result;
    }

    // Equality
    static inline bool AFV4_EQUAL(AF_Vec4 v1, AF_Vec4 v2)
    {
        return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w);
    }

    // division by vector 3
    static inline AF_Vec4 AFV4_DIV(AF_Vec4 v1, AF_Vec4 v2)
    {
        AF_Vec4 result;
        result.x = v1.x / v2.x;
        result.y = v1.y / v2.y;
        result.z = v1.z / v2.z;
        result.w = v1.w / v2.w;
        return result;
    }


    // vec4_dot product of two vectors
    static inline float AFV4_DOT(AF_Vec4 v1, AF_Vec4 v2)
    {
        float _dot = 0.0f;
        _dot += v1.x * v2.x;
        _dot += v1.y * v2.y;
        _dot += v1.z * v2.z;
        _dot += v1.w * v2.w;
        return _dot;
    }

    // Cross product of two vectors
    static inline AF_Vec4 AFV4_CROSS(AF_Vec4 v1, AF_Vec4 v2)
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
    static inline AF_Vec4 AFV4_NORMALIZE(AF_Vec4 v)
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
    static inline float AFV4_MAGNITUDE(AF_Vec4 v)
    {
        float magnitude = 0.0f;
        magnitude += v.x * v.x;
        magnitude += v.y * v.y;
        magnitude += v.z * v.z;
        magnitude += v.w * v.w;
        return sqrt(magnitude);
    }

    // Distance between two vectors
    static inline float AFV4_DISTANCE(AF_Vec4 v1, AF_Vec4 v2)
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
    static inline AF_Vec4 AFV4_PROJECTION(AF_Vec4 v1, AF_Vec4 v2){
        // project v1 onto v2
        // P = (P.Q/|Q|^2) * Q

        // Dot v1 . v2
        float nom = AFV4_DOT(v1, v2);

        // Magnitude squared v2 ^2
        float denom = AFV4_MAGNITUDE(v2);
        denom *= denom;

        // nom / denom
        // Check for divide by zero
        float epsilon = 1e-6; // Threshold for considering magnitude as zero
        if(denom < epsilon){
            AF_Vec4 returnVec = {0.0f, 0.0f, 0.0f, 0.0f};
            return returnVec;
        }
        float scalar = nom / denom;
        
        // scalar * v2
        AF_Vec4 v3 = AFV4_MULT_SCALAR(v2, scalar);
        return v3;
    }

    static inline void AFV4_ORTHOGONALIZE(AF_Vec4* v1, AF_Vec4* v2, AF_Vec4* v3) {
        // vec4_orthogonalize using Gram-Schmidt process
        double scaling_factor;

        // vec4_orthogonalize v1
        *v1 = AFV4_NORMALIZE(*v1);

        // vec4_orthogonalize v2 against v1
        scaling_factor = AFV4_DOT(*v2, *v1);
        v2->x -= scaling_factor * v1->x;
        v2->y -= scaling_factor * v1->y;
        v2->z -= scaling_factor * v1->z;
        v2->w -= scaling_factor * v1->w;
        *v2 = AFV4_NORMALIZE(*v2);

        // vec4_orthogonalize v3 against v1 and v2
        scaling_factor = AFV4_DOT(*v3, *v1);
        v3->x -= scaling_factor * v1->x;
        v3->y -= scaling_factor * v1->y;
        v3->z -= scaling_factor * v1->z;
        v3->w -= scaling_factor * v1->w;

        scaling_factor = AFV4_DOT(*v3, *v2);
        v3->x -= scaling_factor * v2->x;
        v3->y -= scaling_factor * v2->y;
        v3->z -= scaling_factor * v2->z;
        v3->w -= scaling_factor * v2->w;

        *v3 = AFV4_NORMALIZE(*v3);
    }//


#ifdef __cplusplus
}
#endif


#endif  // AF_VEC4_H
