#pragma once
#include "ray.h"

//todo: optimize here per section 6.2
float hit_sphere(const point3& center, float radius, const ray& r) {
	auto oc = r.origin - center;
	auto a = r.direction.dot(r.direction);
	auto b = 2.0f * r.direction.dot(oc);
	auto c = oc.dot(oc) - radius * radius;
	auto discriminant = b * b - 4 * a * c;
	if (discriminant >= 0)
		return (- b - sqrt(discriminant)) / (2 * a);

	return -1.0f;
}


bool hit_sphere_normal(const ray& ray, const point3& sphere_center, const float radius, vec3& normal)
{
	auto sph_hit_dist = hit_sphere(sphere_center, radius, ray);
	if (sph_hit_dist >= 0)
	{
		auto sph_hit = ray.at(sph_hit_dist);
		normal = (sph_hit - sphere_center).unit_vector();
		return true;
	}
	return false;
}