// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "vec3.h"
#include "Color.h"
#include "ray.h"
using namespace std;

const int width = 1080;
const float aspect_ratio = 16.0 / 9.0;
const int height = static_cast<int>(width / aspect_ratio);

const float fov = 90;
const float viewport_width = 2.0;
const float viewport_height = static_cast<int>(viewport_width / aspect_ratio);
const float focal_length = 1.0;

vec3 origin = vec3();
auto horizontal = vec3(viewport_width, 0, 0);
auto vertical = vec3(0, viewport_height, 0);
auto lower_left_direction = -horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);



color ray_color(const ray& ray)
{
	point3 pt = ray.at(focal_length);
	color col((pt.x + viewport_width / 2) / viewport_width, (pt.y + viewport_height / 2) / viewport_height, 0);
	return col;
}

int main(int argc, char* argv[])
{
	cerr << "Creating image with width " << width << " and height " << height << endl;

	ofstream outfile;
	outfile.open(argv[1]);

	outfile << "P3\n" << width << ' ' << height << "\n255\n";
	for (size_t y = 0; y < height; y++)
	{
		if (y % 10 == 0)
			std::cerr << "Progress: line " << y << endl;

		for (size_t x = 0; x < width; x++)
		{
			float u = (x + .5) / width;
			float v = (y + .5) / height;
			ray r(origin, (lower_left_direction + horizontal * u + vertical * v).unit_vector());
			color col = ray_color(r);
			write_color(outfile, col);
		}
	}
	outfile.close();
}
