#pragma once

#include "ray.h"

class hit_record
{
public:
	point3 p;
	vec3 normal;
	float t;
	bool front_face;

	void set_face_normal(const ray& r, const vec3& outward_normal)
	{
		front_face = outward_normal.dot(r.direction) < 0.0f;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class hittable
{
public:
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};