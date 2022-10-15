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

    vec3 operator+(const vec3& other) const
    {
        vec3 res(x + other.x, y + other.y, z + other.z);
        return res;
    }
    vec3 operator-(const vec3& other) const
    {
        vec3 res(x - other.x, y - other.y, z - other.z);
        return res;
    }
    vec3 operator*(const vec3& other) const
    {
        vec3 res(x * other.x, y * other.y, z * other.z);
        return res;
    }
    vec3 operator/(const vec3& other) const
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

    float length() const
    {
        return sqrt(length_squared());
    }

    float length_squared() const
    {
        return x * x + y * y + z * z;
    }

    float dot(const vec3& other) const
    {
        return x * other.x +
               y * other.y +
               z * other.z;
    }
    float cross(const vec3& other) const
    {
        return x * other.x +
               y * other.y +
               z * other.z;
    }


    std::ostream& operator<<(std::ostream& out) const {
        return out << x << ' ' << y << ' ' << z;
    }

    vec3 operator*(float other) const
    {
        return vec3(x * other, y * other, z * other);
    }

    vec3 operator/(float other) const
    {
        return *this * (1 / other);
    }

    vec3 cross(vec3& other) const
    {
        return vec3(y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x);
    }

    vec3 unit_vector() const {
        return *this / length();
    }

    vec3 operator-() const
    {
        return {-x, -y, -z};
    }
};

using point3 = vec3;
using color = vec3;


inline vec3 operator*(float lhs, const vec3& rhs)
{
    return rhs * lhs;
}

#endif //PATH_TRACER_VEC3_H
