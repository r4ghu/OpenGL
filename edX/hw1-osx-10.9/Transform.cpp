// Transform.cpp: implementation of the Transform class.


#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
    glm::mat3 v = glm::mat3(
    axis.x*axis.x, axis.x*axis.y, axis.x*axis.z,
    axis.y*axis.x, axis.y*axis.y, axis.y*axis.z,
    axis.z*axis.x, axis.z*axis.y, axis.z*axis.z
    );
    
    glm::mat3 v2 = glm::mat3(
        0, -axis.z, axis.y,
        axis.z, 0, -axis.x,
        -axis.y, axis.x, 0
        );
    float theta = (degrees * pi)/180.0;
    glm::mat3 R = glm::mat3(1.0f) * cos(theta) + v*(1-cos(theta)) + sin(theta)*v2;

  // You will change this return call
    return R;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
    glm::mat3 eyeMat = rotate(degrees,glm::normalize(-up));
    eye = eyeMat*eye;
    up = eyeMat*up;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
    glm::vec3 rotVec = glm::cross(up,eye);
    glm::mat3 upMat = rotate(degrees,glm::normalize(rotVec));
    up = upMat*up;
    eye = upMat*eye;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE
    glm::vec3 center = glm::vec3(0,0,0);
    glm::mat4 LA = glm::lookAt(eye,center,up);
    return LA;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
