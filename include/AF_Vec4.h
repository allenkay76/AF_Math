#ifndef AF_VEC4_H
#define AF_VEC4_H
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        float x, y, z, w;
    } AF_Vec4;

    //  addition by vector 3
    static inline AF_Vec4 add_vec4(AF_Vec4 v1, AF_Vec4 v2)
    {
        AF_Vec4 result;
        result.x = v1.x + v2.x;
        result.y = v1.y + v2.y;
        result.z = v1.z + v2.z;
        result.w = v1.w + v2.w;
        return result;  
    } 


    // subtraction by vector 3
    static inline AF_Vec4 minus_vec4(AF_Vec4 v1, AF_Vec4 v2)
    {
        AF_Vec4 result;
        result.x = v1.x - v2.x;
        result.y = v1.y - v2.y;
        result.z = v1.z - v2.z;
        result.w = v1.w - v2.w;
        return result;
    }

    // multiplication by scalar
    static inline AF_Vec4 mult_vec4_scalar(AF_Vec4 v, float f)
    {
        AF_Vec4 result;
        result.x = v.x * f;
        result.y = v.y * f;
        result.z = v.z * f;
        result.w = v.w * f;
        return result;
    }

    // multiplication by vector 3
    static inline AF_Vec4 mult_vec4(AF_Vec4 v1, AF_Vec4 v2)
    {
        AF_Vec4 result;
        result.x = v1.x * v2.x;
        result.y = v1.y * v2.y;
        result.z = v1.z * v2.z;
        result.w = v1.w * v2.w;
        return result;
    }

    // division by scalar
    static inline AF_Vec4 div_vec3_scalar(AF_Vec4 v, float f)    
    {
        AF_Vec4 result;
        result.x = v.x / f;
        result.y = v.y / f;
        result.z = v.z / f;
        result.w = v.w / f;
        return result;
    }

    // division by vector 3
    static inline AF_Vec4 div_vec3(AF_Vec4 v1, AF_Vec4 v2)
    {
        AF_Vec4 result;
        result.x = v1.x / v2.x;
        result.y = v1.y / v2.y;
        result.z = v1.z / v2.z;
        result.w = v1.w / v2.w;
        return result;
    }


    // Dot product of two vectors
    static inline float dot(AF_Vec4 v1, AF_Vec4 v2)
    {
        float dot = 0.0f;
        dot += v1.x * v2.x;
        dot += v1.y * v2.y;
        dot += v1.z * v2.z;
        dot += v1.w * v2.w;
        return dot;
    }

    // Cross product of two vectors
    static inline AF_Vec4 cross(AF_Vec4 v1, AF_Vec4 v2)
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
    static inline AF_Vec4 normalize(AF_Vec4 v)
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
    static inline float magnitude(AF_Vec4 v)
    {
        float magnitude = 0.0f;
        magnitude += v.x * v.x;
        magnitude += v.y * v.y;
        magnitude += v.z * v.z;
        magnitude += v.w * v.w;
        return sqrt(magnitude);
    }

    // Distance between two vectors
    static inline float distance(AF_Vec4 v1, AF_Vec4 v2)
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
    static inline AF_Vec4 projection(AF_Vec4 v1, AF_Vec4 v2){
        // project v1 onto v2
        // P = (P.Q/|Q|^2) * Q

        // Dot v1 . v2
        float nom = dot(v1, v2);

        // Magnitude squared v2 ^2
        float denom = magnitude(v2);
        denom *= denom;

        // nom / denom
        // Check for divide by zero
        float epsilon = 1e-6; // Threshold for considering magnitude as zero
        if(denom < epsilon){
            return AF_Vec4{0.0f, 0.0f, 0.0f};
        }
        float scalar = nom / denom;
        
        // scalar * v2
        AF_Vec4 v3 = mult_vec4_scalar(v2, scalar);
        return v3;
    }

    static inline void orthogonalize(AF_Vec4* v1, AF_Vec4* v2, AF_Vec4* v3) {
        // Orthogonalize using Gram-Schmidt process
        double scaling_factor;

        // Orthogonalize v1
        *v1 = normalize(*v1);

        // Orthogonalize v2 against v1
        scaling_factor = dot(*v2, *v1);
        v2->x -= scaling_factor * v1->x;
        v2->y -= scaling_factor * v1->y;
        v2->z -= scaling_factor * v1->z;
        v2->w -= scaling_factor * v1->w;
        *v2 = normalize(*v2);

        // Orthogonalize v3 against v1 and v2
        scaling_factor = dot(*v3, *v1);
        v3->x -= scaling_factor * v1->x;
        v3->y -= scaling_factor * v1->y;
        v3->z -= scaling_factor * v1->z;
        v3->w -= scaling_factor * v1->w;

        scaling_factor = dot(*v3, *v2);
        v3->x -= scaling_factor * v2->x;
        v3->y -= scaling_factor * v2->y;
        v3->z -= scaling_factor * v2->z;
        v3->w -= scaling_factor * v2->w;

        *v3 = normalize(*v3);
    }//


#ifdef __cplusplus
}
#endif


#endif  // AF_VEC4_H