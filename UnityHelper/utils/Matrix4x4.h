#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "CommonStructs.h"

using namespace CommonStructs;

class Matrix4x4 
{
public:
    Matrix4x4();	

    // Returns the identity matrix (Read Only).
    static Matrix4x4 identity;	

    // Returns a matrix with all elements set to zero (Read Only).
    static Matrix4x4 zero;	

    // This property takes a projection matrix and returns the six plane coordinates that define a projection frustum.
    FrustumPlanes decomposeProjection;	

    // The determinant of the matrix.
    float determinant;	

    // The inverse of this matrix (Read Only).
    Matrix4x4 *inverse;	

    // Is this the identity matrix?
    bool isIdentity;

    // Attempts to get a scale value from the matrix.
    Vector3 lossyScale;	

    // Attempts to get a rotation quaternion from this matrix.
    Quaternion rotation;	

    // Access element at [row, column].
    // float this[int,int]	

    // Returns the transpose of this matrix (Read Only).
    Matrix4x4 *transpose;
};

#endif