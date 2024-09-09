#ifndef AFM4_H
#define AFM4_H
#include "AF_Vec4.h"
#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        AF_Vec4 rows[4];
    } AF_Mat4;
   
    static inline AF_Mat4 AFM4_IDENTITY(void){
	AF_Mat4 returnMatrix = {{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
    		{0, 0, 1, 0},
		{0, 0, 0, 1}			// Row order position
	}};
	return returnMatrix;
    }

    static inline AF_Mat4 AFM4_ZERO(void){
	AF_Mat4 returnMatrix = {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
    		{0, 0, 0, 0},
		{0, 0, 0, 0}			// Row order position
	}};
	return returnMatrix;
    }
 
        //  addition by vector 3
    static inline AF_Mat4 AFM4_ADD_M4(AF_Mat4 _leftM4, AF_Mat4 _rightM4)
    {
        AF_Mat4 result = {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	    }};

        result.rows[0] = AFV4_ADD(_leftM4.rows[0], _rightM4.rows[0]);
        result.rows[1] = AFV4_ADD(_leftM4.rows[1], _rightM4.rows[1]);
        result.rows[2] = AFV4_ADD(_leftM4.rows[2], _rightM4.rows[2]);
        result.rows[3] = AFV4_ADD(_leftM4.rows[3], _rightM4.rows[3]);
        return result;  
    }

    // subtraction by vector 3
    static inline AF_Mat4 AFM4_MINUS_M4(AF_Mat4 _leftM4, AF_Mat4 _rightM4)
    {
        AF_Mat4 result = {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	    }};

        result.rows[0] = AFV4_ADD(_leftM4.rows[0], _rightM4.rows[0]);
        result.rows[1] = AFV4_ADD(_leftM4.rows[1], _rightM4.rows[1]);
        result.rows[2] = AFV4_ADD(_leftM4.rows[2], _rightM4.rows[2]);
        result.rows[3] = AFV4_ADD(_leftM4.rows[3], _rightM4.rows[3]);
        return result;  
    }

    // multiplication by scalar
    static inline AF_Mat4 AFM4_MULT_SCALAR (AF_Mat4 _matrix, AF_FLOAT _f)
    {
        AF_Mat4 result = {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	    }};

        result.rows[0] = AFV4_MULT_SCALAR(_matrix.rows[0], _f);
        result.rows[1] = AFV4_MULT_SCALAR(_matrix.rows[1], _f);
        result.rows[2] = AFV4_MULT_SCALAR(_matrix.rows[2], _f);
        result.rows[3] = AFV4_MULT_SCALAR(_matrix.rows[3], _f);
        return result;  
    }

    // multiplication by mat 4
    static inline AF_Mat4 AFM4_MULT_M4(AF_Mat4 _lefm4, AF_Mat4 _rightm4)
    {
        AF_Mat4 result = {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	    }};

        result.rows[0] = AFV4_MULT(_lefm4.rows[0], _rightm4.rows[0]);
        result.rows[1] = AFV4_MULT(_lefm4.rows[1], _rightm4.rows[1]);
        result.rows[2] = AFV4_MULT(_lefm4.rows[2], _rightm4.rows[2]);
        result.rows[3] = AFV4_MULT(_lefm4.rows[3], _rightm4.rows[3]);
        return result;  
    }

	// Function to multiply two 4x4 matrices
	static inline AF_Mat4 AFM4_DOT_M4(AF_Mat4 left, AF_Mat4 right) {
	    AF_Mat4 result = {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	    }};

	    for (int i = 0; i < 4; ++i) {
		result.rows[i].x = left.rows[i].x * right.rows[0].x +
				   left.rows[i].y * right.rows[1].x +
				   left.rows[i].z * right.rows[2].x +
				   left.rows[i].w * right.rows[3].x;

		result.rows[i].y = left.rows[i].x * right.rows[0].y +
				   left.rows[i].y * right.rows[1].y +
				   left.rows[i].z * right.rows[2].y +
				   left.rows[i].w * right.rows[3].y;

		result.rows[i].z = left.rows[i].x * right.rows[0].z +
				   left.rows[i].y * right.rows[1].z +
				   left.rows[i].z * right.rows[2].z +
				   left.rows[i].w * right.rows[3].z;

		result.rows[i].w = left.rows[i].x * right.rows[0].w +
				   left.rows[i].y * right.rows[1].w +
				   left.rows[i].z * right.rows[2].w +
				   left.rows[i].w * right.rows[3].w;
	    }

	    return result;
	}
    // division by scalar
    static inline AF_Mat4 AFM4_DIV_SCALAR(AF_Mat4 _v, AF_FLOAT _f)    
    {
        AF_Mat4 result = {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	    }};

        result.rows[0] = AFV4_DIV_SCALAR(_v.rows[0], _f);
        result.rows[1] = AFV4_DIV_SCALAR(_v.rows[1], _f);
        result.rows[2] = AFV4_DIV_SCALAR(_v.rows[2], _f);
        result.rows[3] = AFV4_DIV_SCALAR(_v.rows[3], _f);
        return result;
    }

    // division by vector 3
    static inline AF_Mat4 AFM4_DIV_M4(AF_Mat4 _lefm4, AF_Mat4 _rightm4)
    {
        AF_Mat4 result = {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	    }};

        result.rows[0] = AFV4_DIV(_lefm4.rows[0], _rightm4.rows[0]);
        result.rows[1] = AFV4_DIV(_lefm4.rows[1], _rightm4.rows[1]);
        result.rows[2] = AFV4_DIV(_lefm4.rows[2], _rightm4.rows[2]);
        result.rows[3] = AFV4_DIV(_lefm4.rows[3], _rightm4.rows[3]);
        return result;
    }


    // Dot product of two vectors
    // Normalize a vector
    // If the magnitude of the vector is zero, the vector is not modified
    static inline AF_Vec4 AFM4_NORMALIZE(AF_Vec4 v)
    {   
        AF_FLOAT magnitude = AF_Math_Sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
        AF_FLOAT epsilon = AF_EPSILON; // Threshold for considering magnitude as zero
        if (magnitude < epsilon) {
            // Return a default unit vector or other appropriate error handling
            return v;
        }
        AF_Vec4 result = { v.x / magnitude, v.y / magnitude, v.z / magnitude, v.w/ magnitude };
        return result;
    }

    // Magnitude of a vector
    static inline AF_FLOAT AFM4_MAGNITUDE(AF_Vec4 v)
    {
        AF_FLOAT magnitude = 0;
        magnitude += v.x * v.x;
        magnitude += v.y * v.y;
        magnitude += v.z * v.z;
        magnitude += v.w * v.w;
        return AF_Math_Sqrt(magnitude);
    }

    // Distance between two vectors
    static inline AF_FLOAT AFM4_DISTANCE(AF_Vec4 v1, AF_Vec4 v2)
    {
        AF_FLOAT distance = 0;
        distance += (v1.x - v2.x) * (v1.x - v2.x);
        distance += (v1.y - v2.y) * (v1.y - v2.y);
        distance += (v1.z - v2.z) * (v1.z - v2.z);
        distance += (v1.w - v2.w) * (v1.w - v2.w);
        return AF_Math_Sqrt(distance);
    }

    // Projection of one vector onto another
    // if denominator is zero, the vector returned is 0,0,0
    static inline AF_Vec4 AFM4_PROJECTION(AF_Vec4 _v1, AF_Vec4 _v2){
        // project v1 onto v2
        // P = (P.Q/|Q|^2) * Q

        // Dot v1 . v2
        AF_FLOAT nom = AFV4_DOT(_v1, _v2);

        // Magnitude squared v2 ^2
        AF_FLOAT denom = AFV4_MAGNITUDE(_v2);
        denom *= denom;

        // nom / denom
        // Check for divide by zero
        AF_FLOAT epsilon = AF_EPSILON; // Threshold for considering magnitude as zero
        if(denom < epsilon){
            AF_Vec4 returnVec4 = {0, 0, 0, 0};
            return returnVec4;
        }
        AF_FLOAT scalar = nom / denom;
        
        // scalar * v2
        AF_Vec4 _v3 = {0,0,0,0}; 
	_v3 = AFV4_MULT_SCALAR(_v2, scalar);
        return _v3;
    }

    // Calculate rotation and return mat4
    static inline AF_Mat4 AFM4_ROTATE_V4(AF_Mat4 _matrixToRotate, AF_Vec4 _rotation){
	// Apply rotation
	// x axis matrix
	AF_FLOAT cosX = AF_Math_Cos(_rotation.x);
	AF_FLOAT sinX = AF_Math_Sin(_rotation.x);
	AF_Vec4 row1 = {0,0,0,0};
        row1 = _matrixToRotate.rows[0];
	AF_Vec4 row2 = {0,0,0,0};
        row2 = _matrixToRotate.rows[1];
	AF_Vec4 row3 = {0,0,0,0};
        row3 = _matrixToRotate.rows[2];
	AF_Vec4 row4 = {0,0,0,0};
        row4 = _matrixToRotate.rows[3];

        AF_Mat4 xAxisMatrix = {{
		{row1.x, row1.y, row1.z, row1.z},
		{row2.x, cosX, -sinX, row2.w},
    		{row3.x, sinX, cosX, row3.w},
		{row4.x, row4.y, row4.z, row4.w}			// Row order position
	}};
	
	// y axis matrix 
	AF_FLOAT cosY = AF_Math_Cos(_rotation.y);
	AF_FLOAT sinY = AF_Math_Sin(_rotation.y);
	AF_Mat4 yAxisMatrix = {{
		{cosY, row1.y, sinY, row1.w},
		{row2.x, row2.y, row2.z, row2.z},
    		{-sinY, row3.y, cosY, row3.w},
		{row4.x, row4.y, row4.z, row4.w}	// Row order position
	}};

	// z axis matrix 
	AF_FLOAT cosZ = AF_Math_Cos(_rotation.z);
	AF_FLOAT sinZ = AF_Math_Sin(_rotation.z);
	AF_Mat4 zAxisMatrix = {{
		{cosZ, -sinZ, row1.z, row1.w},
		{sinZ, cosZ, row2.z, row2.w},
    		{row3.x, row3.y, row3.z, row3.w},
		{row4.x, row4.y, row4.z, row4.w}	// Row order position
	}};

	AF_Mat4 rotatedMatrix =  {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
    		{0, 0, 0, 0},
		{0, 0, 0, 0}			// Row order position
	}};
				
        rotatedMatrix = AFM4_DOT_M4(AFM4_DOT_M4(zAxisMatrix, yAxisMatrix), xAxisMatrix);
	return _matrixToRotate;//rotatedMatrix;
}

    inline static AF_Mat4 AFM4_SCALE_V4(AF_Mat4 _matrixToScale, AF_Vec4 _scale){
	AF_Vec4 row1 = {0,0,0,0}; 
        row1 = _matrixToScale.rows[0];
	AF_Vec4 row2 = {0,0,0,0};
        row2 = _matrixToScale.rows[1];
	AF_Vec4 row3 = {0,0,0,0};
        row3 = _matrixToScale.rows[2];
	AF_Vec4 row4 = {0,0,0,0};
        row4 = _matrixToScale.rows[3];

	// Apply scale
	AF_Mat4 scaleMatrix = {{
		{_scale.x * row1.x, row1.y, row1.z, row1.w},
		{row2.x, _scale.y * row2.y, row2.z, row2.w},
    		{row3.x, row3.y, _scale.z * row3.z, row3.w},
		{row4.x, row4.y, row4.z, row4.w}			// Row order position
	}};
	return scaleMatrix;

    }

#ifdef __cplusplus
}
#endif


#endif  // AFM4_H
