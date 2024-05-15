#ifndef AF_VEC3_H
#define AF_VEC3_H
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        float x, y, z;
    } AF_Vec3;

    // Overloaded operators addition by vector 3
    static inline AF_Vec3 add_vec3(AF_Vec3 v1, AF_Vec3 v2)
    {
        AF_Vec3 result;
        result.x = v1.x + v2.x;
        result.y = v1.y + v2.y;
        result.z = v1.z + v2.z;
        return result;  
    } 

    // Overloaded operators subtraction by vector 3
    static inline AF_Vec3 minus_vec3(AF_Vec3 v1, AF_Vec3 v2)
    {
        AF_Vec3 result;
        result.x = v1.x - v2.x;
        result.y = v1.y - v2.y;
        result.z = v1.z - v2.z;
        return result;
    }

    // Overloaded operators multiplication by scalar
    static inline AF_Vec3 mult_vec3_scalar(AF_Vec3 v, float f)
    {
        AF_Vec3 result;
        result.x = v.x * f;
        result.y = v.y * f;
        result.z = v.z * f;
        return result;
    }

    // Overloaded operators multiplication by vector 3
    static inline AF_Vec3 mult_vec3(AF_Vec3 v1, AF_Vec3 v2)
    {
        AF_Vec3 result;
        result.x = v1.x * v2.x;
        result.y = v1.y * v2.y;
        result.z = v1.z * v2.z;
        return result;
    }

    // Overloaded operators division by scalar
    static inline AF_Vec3 div_vec3_scalar(AF_Vec3 v, float f)    
    {
        AF_Vec3 result;
        result.x = v.x / f;
        result.y = v.y / f;
        result.z = v.z / f;
        return result;
    }

    // Overloaded operators division by vector 3
    static inline AF_Vec3 div_vec3(AF_Vec3 v1, AF_Vec3 v2)
    {
        AF_Vec3 result;
        result.x = v1.x / v2.x;
        result.y = v1.y / v2.y;
        result.z = v1.z / v2.z;
        return result;
    }


    // Dot product of two vectors
    static inline float dot(AF_Vec3 v1, AF_Vec3 v2)
    {
        float dot = 0.0f;
        dot += v1.x * v2.x;
        dot += v1.y * v2.y;
        dot += v1.z * v2.z;
        return dot;
    }

    // Cross product of two vectors
    static inline AF_Vec3 cross(AF_Vec3 v1, AF_Vec3 v2)
    {

        AF_Vec3 cross;
        cross.x = v1.y * v2.z - v1.z * v2.y;
        cross.y = v1.z * v2.x - v1.x * v2.z;
        cross.z = v1.x * v2.y - v1.y * v2.x;
        return cross;
    }

    // Normalize a vector
    static inline AF_Vec3 normalize(AF_Vec3 v)
    {    
        float magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        AF_Vec3 result = { v.x / magnitude, v.y / magnitude, v.z / magnitude };
        return result;
    }

    // Magnitude of a vector
    static inline float magnitude(AF_Vec3 v)
    {
        float magnitude = 0.0f;
        magnitude += v.x * v.x;
        magnitude += v.y * v.y;
        magnitude += v.z * v.z;
        return sqrt(magnitude);
    }

    // Distance between two vectors
    static inline float distance(AF_Vec3 v1, AF_Vec3 v2)
    {
        float distance = 0.0f;
        distance += (v1.x - v2.x) * (v1.x - v2.x);
        distance += (v1.y - v2.y) * (v1.y - v2.y);
        distance += (v1.z - v2.z) * (v1.z - v2.z);
        return sqrt(distance);
    }

    // Projection of one vector onto another
    static inline AF_Vec3 projection(AF_Vec3 v1, AF_Vec3 v2){
        // project v1 onto v2
        // P = (P.Q/|Q|^2) * Q

        // Dot v1 . v2
        float nom = dot(v1, v2);

        // Magnitude squared v2 ^2
        float denom = magnitude(v2);
        denom *= denom;

        // nom / denom
        float scalar = nom / denom;
        
        // scalar * v2
        AF_Vec3 v3 = mult_vec3_scalar(v2, scalar);
        return v3;
    }

    static inline void orthogonalize(AF_Vec3* v1, AF_Vec3* v2, AF_Vec3* v3) {
        // Orthogonalize using Gram-Schmidt process
        double scaling_factor;

        // Orthogonalize v1
        *v1 = normalize(*v1);

        // Orthogonalize v2 against v1
        scaling_factor = dot(*v2, *v1);
        v2->x -= scaling_factor * v1->x;
        v2->y -= scaling_factor * v1->y;
        v2->z -= scaling_factor * v1->z;
        *v2 = normalize(*v2);

        // Orthogonalize v3 against v1 and v2
        scaling_factor = dot(*v3, *v1);
        v3->x -= scaling_factor * v1->x;
        v3->y -= scaling_factor * v1->y;
        v3->z -= scaling_factor * v1->z;

        scaling_factor = dot(*v3, *v2);
        v3->x -= scaling_factor * v2->x;
        v3->y -= scaling_factor * v2->y;
        v3->z -= scaling_factor * v2->z;

        *v3 = normalize(*v3);
    }//


#ifdef __cplusplus
}
#endif


#endif  // AF_MATH_H