#pragma once
#include "ray.h"
#include "vec3.h"

color ray_color(const ray& ray);


extern "C" {
	__declspec(dllexport)  int _cdecl get_width();
	__declspec(dllexport)  int _cdecl get_height();
	__declspec(dllexport)  void _cdecl render(unsigned char* frame);
}