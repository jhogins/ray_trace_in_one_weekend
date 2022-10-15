//
// Created by jonathanh on 10/15/2022.
//

#ifndef PATH_TRACER_VEC3_H
#define PATH_TRACER_VEC3_H

class vec3
{
public:
    float x;
    float y;
    float z;

    vec3(float x, float y, float z)
            :x(x), y(y), z(z)
    {}
    vec3()
            :x(0), y(0), z(0)
    {}

    vec3 operator+(const vec3& other)
    {
        vec3 res(x + other.x, y + other.y, z + other.z);
        return res;
    }
    vec3 operator-(const vec3& other)
    {
        vec3 res(x - other.x, y - other.y, z - other.z);
        return res;
    }
    vec3 operator*(const vec3& other)
    {
        vec3 res(x * other.x, y * other.y, z * other.z);
        return res;
    }
    vec3 operator/(const vec3& other)
    {
        vec3 res(x / other.x, y / other.y, z / other.z);
        return res;
    }

    vec3& operator+=(const vec3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    vec3& operator-=(const vec3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    vec3& operator*=(const vec3& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    vec3& operator/=(const vec3& other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    float length()
    {
        return sqrt(length_squared());
    }

    float length_squared()
    {
        return x * x + y * y + z * z;
    }

    float dot(const vec3& other)
    {
        return x * other.x +
               y * other.y +
               z * other.z;
    }
    float cross(const vec3& other)
    {
        return x * other.x +
               y * other.y +
               z * other.z;
    }


    std::ostream& operator<<(std::ostream& out) {
        return out << x << ' ' << y << ' ' << z;
    }

    vec3 operator*(float other)
    {
        return vec3(x * other, y * other, z * other);
    }

    vec3 operator/(float other)
    {
        return *this * (1 / other);
    }

    vec3 cross(vec3& other)
    {
        return vec3(y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x);
    }
};

using point3 = vec3;
using color = vec3;
#endif //PATH_TRACER_VEC3_H
