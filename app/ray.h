#pragma once

#include "vec3.h"

class ray {
public:
	ray(const vec3& origin, const vec3& direction)
		: origin(origin), direction(direction)
	{

	}

	vec3 origin;
	vec3 direction;

	vec3 at(float d) const
	{
		return origin + d * direction;
	}
};
