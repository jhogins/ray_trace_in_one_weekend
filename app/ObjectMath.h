#pragma once
#include "ray.h"

bool hit_sphere(const point3& center, float radius, const ray& r) {
	auto oc = r.origin - center;
	auto a = r.direction.dot(r.direction);
	auto b = 2.0f * r.direction.dot(oc);
	auto c = oc.dot(oc) - radius * radius;
	auto discriminant = b * b - 4 * a * c;
	if (discriminant >= 0)
		return true;

	return false;
}
