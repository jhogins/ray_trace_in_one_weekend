#pragma once

#include "vec3.h"
#include <iostream>

void write_color(std::ostream& stream, color& color)
{
	stream << static_cast<int>(color.x * (255.99)) << " "
		<< static_cast<int>(color.y * (255.99)) << " "
		<< static_cast<int>(color.z * (255.99)) << std::endl;
}

void write_color(std::ofstream& stream, unsigned char r, unsigned char g, unsigned char b)
{
	stream << static_cast<int>(r) << " " << static_cast<int>(g) << " " << static_cast<int>(b) << std::endl;
}
