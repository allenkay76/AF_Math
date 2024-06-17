#ifndef AF_VEC3_H
#define AF_VEC3_H
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        float x, y, z;
    } AF_Vec3;

    //  addition by vector 3
    static inline AF_Vec3 AFV3_ADD(AF_Vec3 v1, AF_Vec3 v2)
    {
        AF_Vec3 result;
        result.x = v1.x + v2.x;
        result.y = v1.y + v2.y;
        result.z = v1.z + v2.z;
        return result;  
    } 


    // subtraction by vector 3
    static inline AF_Vec3 AFV3_MINUS(AF_Vec3 v1, AF_Vec3 v2)
    {
        AF_Vec3 result;
        result.x = v1.x - v2.x;
        result.y = v1.y - v2.y;
        result.z = v1.z - v2.z;
        return result;
    }

    // multiplication by scalar
    static inline AF_Vec3 AFV3_MULT_SCALAR(AF_Vec3 v, float f)
    {
        AF_Vec3 result;
        result.x = v.x * f;
        result.y = v.y * f;
        result.z = v.z * f;
        return result;
    }

    // multiplication by vector 3
    static inline AF_Vec3 AFV3_MULT(AF_Vec3 v1, AF_Vec3 v2)
    {
        AF_Vec3 result;
        result.x = v1.x * v2.x;
        result.y = v1.y * v2.y;
        result.z = v1.z * v2.z;
        return result;
    }

    // division by scalar
    static inline AF_Vec3 AFV3_DIV_SCALAR(AF_Vec3 v, float f)    
    {
        AF_Vec3 result;
        result.x = v.x / f;
        result.y = v.y / f;
        result.z = v.z / f;
        return result;
    }

    // division by vector 3
    static inline AF_Vec3 AFV3_DIV(AF_Vec3 v1, AF_Vec3 v2)
    {
        AF_Vec3 result;
        result.x = v1.x / v2.x;
        result.y = v1.y / v2.y;
        result.z = v1.z / v2.z;
        return result;
    }

  

    // Equality check
    static inline int AFV3_EQUAL(const AF_Vec3 v1, const AF_Vec3 v2){
        return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
    }


    // vec3_dot product of two vectors
    static inline float AFV3_DOT(AF_Vec3 v1, AF_Vec3 v2)
    {
        float _dot = 0.0f;
        _dot += v1.x * v2.x;
        _dot += v1.y * v2.y;
        _dot += v1.z * v2.z;
        return _dot;
    }

    // Cross product of two vectors
    static inline AF_Vec3 AFV3_CROSS(AF_Vec3 v1, AF_Vec3 v2)
    {

        AF_Vec3 cross;
        cross.x = v1.y * v2.z - v1.z * v2.y;
        cross.y = v1.z * v2.x - v1.x * v2.z;
        cross.z = v1.x * v2.y - v1.y * v2.x;
        return cross;
    }

    // Normalize a vector
    // If the magnitude of the vector is zero, the vector is not modified
    static inline AF_Vec3 AFV3_NORMALIZE(AF_Vec3 v)
    {   
        float magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        float epsilon = 1e-6; // Threshold for considering magnitude as zero
        if (magnitude < epsilon) {
            // Return a default unit vector or other appropriate error handling
            return v;
        }
        AF_Vec3 result = { v.x / magnitude, v.y / magnitude, v.z / magnitude };
        return result;
    }

    // Magnitude of a vector
    static inline float AFV3_MAGNITUDE(AF_Vec3 v)
    {
        float magnitude = 0.0f;
        magnitude += v.x * v.x;
        magnitude += v.y * v.y;
        magnitude += v.z * v.z;
        return sqrt(magnitude);
    }

    // Distance between two vectors
    static inline float AFV3_DISTANCE(AF_Vec3 v1, AF_Vec3 v2)
    {
        float distance = 0.0f;
        distance += (v1.x - v2.x) * (v1.x - v2.x);
        distance += (v1.y - v2.y) * (v1.y - v2.y);
        distance += (v1.z - v2.z) * (v1.z - v2.z);
        return sqrt(distance);
    }

    // Projection of one vector onto another
    // if denominator is zero, the vector returned is 0,0,0
    static inline AF_Vec3 AFV3_PROJECTION(AF_Vec3 v1, AF_Vec3 v2){
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
            AF_Vec3 v3 = {0.0f, 0.0f, 0.0f};
            return v3;
        }
        float scalar = nom / denom;
        
        // scalar * v2
        AF_Vec3 v3 = AFV3_MULT_SCALAR(v2, scalar);
        return v3;
    }

    static inline void AFV3_ORTHOGANLIZE(AF_Vec3* v1, AF_Vec3* v2, AF_Vec3* v3) {
        // Orthogonalize using Gram-Schmidt process
        double scaling_factor;

        // Orthogonalize v1
        *v1 = AFV3_NORMALIZE(*v1);

        // Orthogonalize v2 against v1
        scaling_factor = AFV3_DOT(*v2, *v1);
        v2->x -= scaling_factor * v1->x;
        v2->y -= scaling_factor * v1->y;
        v2->z -= scaling_factor * v1->z;
        *v2 = AFV3_NORMALIZE(*v2);

        // Orthogonalize v3 against v1 and v2
        scaling_factor = AFV3_DOT(*v3, *v1);
        v3->x -= scaling_factor * v1->x;
        v3->y -= scaling_factor * v1->y;
        v3->z -= scaling_factor * v1->z;

        scaling_factor = AFV3_DOT(*v3, *v2);
        v3->x -= scaling_factor * v2->x;
        v3->y -= scaling_factor * v2->y;
        v3->z -= scaling_factor * v2->z;

        *v3 = AFV3_NORMALIZE(*v3);
    }//


#ifdef __cplusplus
}
#endif


#endif  // AF_VEC3_H
