#pragma once
#include "hittable.h"
#include "ObjectMath.h"

class sphere : public hittable
{
public:
	point3 position;
	float radius;

	sphere(const point3& position, float radius)
		: position(position),
		  radius(radius)
	{
	}

	bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override
	{
		vec3 normal;
		return hit_sphere_normal(r, t_min, t_max, position, radius, rec);
	}
};
