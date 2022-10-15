#pragma once

#include "vec3.h"
#include <iostream>

void write_color(std::ostream& stream, color& color)
{
	stream << static_cast<int>(color.x * (255.99)) << " "
		<< static_cast<int>(color.y * (255.99)) << " "
		<< static_cast<int>(color.z * (255.99)) << std::endl;
}