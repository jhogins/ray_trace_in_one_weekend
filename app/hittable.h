#pragma once

#include "ray.h"

class hit_record
{
public:
	point3 p;
	vec3 normal;
	float t;
};

class hittable
{
public:
	virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};