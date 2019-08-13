#ifndef FRUSTUM_PLANES_H
#define FRUSTUM_PLANES_H

class FrustumPlanes
{
    // Position in view space of the bottom side of the near projection plane.
    float bottom;	

    // Position in view space of the left side of the near projection plane.
    float left;	

    // Position in view space of the right side of the near projection plane.
    float right;	

    // Position in view space of the top side of the near projection plane.
    float top;	

    // Z distance from the origin of view space to the far projection plane.
    float zFar;	

    // Z distance from the origin of view space to the near projection plane.
    float zNear;	
}

#endif