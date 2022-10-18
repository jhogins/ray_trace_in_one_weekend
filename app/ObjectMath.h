#pragma once
#include "hittable.h"
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


bool hit_sphere_normal(const ray& ray, float t_min, float t_max, const point3& sphere_center, const float radius, hit_record& hit_record)
{
	auto sph_hit_dist = hit_sphere(sphere_center, radius, ray);
	if (sph_hit_dist >= t_min && sph_hit_dist <= t_max)
	{
		auto sph_hit = ray.at(sph_hit_dist);
		hit_record.set_face_normal(ray, (sph_hit - sphere_center) / radius);
		hit_record.p = sph_hit;
		hit_record.t = sph_hit_dist;
		return true;
	}
	return false;
}