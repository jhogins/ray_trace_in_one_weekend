#pragma once
#include "ray.h"
#include "vec3.h"

class camera
{
public:
	camera(float aspect_ratio)
	{
		this->aspect_ratio = aspect_ratio;
		const float viewport_height = 2.0;
		float viewport_width = viewport_height * aspect_ratio;
		const float focal_length = 1.0;

		origin = vec3();
		horizontal = vec3(viewport_width, 0, 0);
		vertical = vec3(0, viewport_height, 0);
		lower_left_direction = -horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);
	}

	ray get_ray(float u, float v) const {
		return ray(origin, lower_left_direction + u * horizontal + v * vertical - origin);
	}
private:
	float aspect_ratio;
	vec3 lower_left_direction;
	vec3 horizontal;
	vec3 vertical;
	vec3 origin;
};
