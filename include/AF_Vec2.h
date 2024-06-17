#ifndef AF_VEC2_H
#define AF_VEC2_H
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        float x, y, z;
    } AF_Vec2;

    //  addition by vector 3
    static inline AF_Vec2 AFV2ADD(AF_Vec2 v1, AF_Vec2 v2)
    {
        AF_Vec2 result;
        result.x = v1.x + v2.x;
        result.y = v1.y + v2.y;
        return result;  
    } 


    // subtraction by vector 3
    static inline AF_Vec2 AFV2_MINUS(AF_Vec2 v1, AF_Vec2 v2)
    {
        AF_Vec2 result;
        result.x = v1.x - v2.x;
        result.y = v1.y - v2.y;
        return result;
    }

    // multiplication by scalar
    static inline AF_Vec2 AFV2_MULT_SCALAR(AF_Vec2 v, float f)
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
    static inline AF_Vec2 AFV2_DIV_SCALAR(AF_Vec2 v, float f)    
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
    static inline float AFV2_DOT(AF_Vec2 v1, AF_Vec2 v2)
    {
        float _dot = 0.0f;
        _dot += v1.x * v2.x;
        _dot += v1.y * v2.y;
        return _dot;
    }


    // Normalize a vector
    // If the magnitude of the vector is zero, the vector is not modified
    static inline AF_Vec2 AFV2_NORMALIZE(AF_Vec2 v)
    {   
        float magnitude = sqrt(v.x * v.x + v.y * v.y);
        float epsilon = 1e-6; // Threshold for considering magnitude as zero
        if (magnitude < epsilon) {
            // Return a default unit vector or other appropriate error handling
            return v;
        }
        AF_Vec2 result = { v.x / magnitude, v.y};
        return result;
    }

    // Magnitude of a vector
    static inline float AFV2_MAGNITUDE(AF_Vec2 v)
    {
        float magnitude = 0.0f;
        magnitude += v.x * v.x;
        magnitude += v.y * v.y;
        return sqrt(magnitude);
    }

    // Distance between two vectors
    static inline float AFV2_DISTANCE(AF_Vec2 v1, AF_Vec2 v2)
    {
        float distance = 0.0f;
        distance += (v1.x - v2.x) * (v1.x - v2.x);
        distance += (v1.y - v2.y) * (v1.y - v2.y);
        return sqrt(distance);
    }



#ifdef __cplusplus
}
#endif


#endif  // AF_VEC2_H
