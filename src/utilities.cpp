#include <utilities.hpp>

Vector3 Utilities::DotProduct(Matrix matrix, Vector3& vector) {
    float v1 = vector.x;
    float v2 = vector.y;
    float v3 = vector.z;

    return Vector3{
        matrix.a11*v1 + matrix.a12*v2 + matrix.a13*v3,
        matrix.a21*v1 + matrix.a22*v2 + matrix.a23*v3,
        matrix.a31*v1 + matrix.a32*v2 + matrix.a33*v3};
}

/*!
    Rotates a vector around the y-axis
    @param angle: Rotation angle in radians
    @param vector: Vector to perform the rotation on
    @return Rotated vector
*/
Vector3 Utilities::RotateAroundY(float angle, Vector3& vector) {
    Matrix rotationMatrix = Matrix(
        cos(angle),     0,      sin(angle),
        0,              1,      0,
        -sin(angle),    0,      cos(angle));
    
    return DotProduct(rotationMatrix, vector);
}

/*!
    Rotates a vector around the x-axis
    @param angle: Rotation angle in radians
    @param vector: Vector to perform the rotation on
    @return Rotated vector
*/
Vector3 Utilities::RotateAroundX(float angle, Vector3& vector) {
    Matrix rotationMatrix = Matrix(
        1,  0,          0,
        0,  cos(angle), -sin(angle),
        0,  sin(angle), cos(angle));

    return DotProduct(rotationMatrix, vector);
}

