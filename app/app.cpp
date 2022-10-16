// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "vec3.h"
#include "Color.h"
#include "ObjectMath.h"
#include "ray.h"
using namespace std;

const int width = 1920;
const float aspect_ratio = 16.0f / 9.0f;
const int height = static_cast<int>(width / aspect_ratio);

const float fov = 90;
const float viewport_width = 2.0;
const float viewport_height = viewport_width / aspect_ratio;
const float focal_length = 1.0;

vec3 origin = vec3();
auto horizontal = vec3(viewport_width, 0, 0);
auto vertical = vec3(0, viewport_height, 0);
auto lower_left_direction = -horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

void write_ppm(unsigned char* frame)
{
	cerr << "Creating image with width " << width << " and height " << height << endl;

	ofstream outfile;
	outfile.open("last_image.ppm");

	outfile << "P3\n" << width << ' ' << height << "\n255\n";

	for (int i = 0; i < width * height; i++)
	{
		write_color(outfile, frame[i * 4], frame[i * 4 + 1], frame[i * 4 + 2]);
	}

	outfile.close();
}

extern "C" {
	color ray_color(const ray& ray)
	{
		//return color(0.0f, 0.0f, 1.0f);
		point3 pt = ray.at(focal_length);
		color col(/*(pt.x + viewport_width / 2) / viewport_width*/0, 0, (pt.y + viewport_height / 2) / viewport_height);

		if (hit_sphere(point3(0, 0, -5.0f), 2.0f, ray))
			col = color(1.0f, 0.f, 0.f);

		return col;
	}
	__declspec(dllexport)  int _cdecl get_width() { return width; }
	__declspec(dllexport)  int _cdecl get_height() { return height; }
	__declspec(dllexport)  void _cdecl render(unsigned char* frame)
	{
		size_t idx = 0;
		for (size_t y = 0; y < height; y++)
		{
			if (y % 10 == 0)
				std::cerr << "Progress: line " << y << endl;

			for (size_t x = 0; x < width; x++)
			{
				float u = (x + .5f) / width;
				float v = (y + .5f) / height;
				ray r(origin, (lower_left_direction + horizontal * u + vertical * v).unit_vector());
				color col = ray_color(r);
				frame[idx * 4] = static_cast<unsigned char>(col.x * 255.99);
				frame[idx * 4 + 1] = static_cast<unsigned char>(col.y * 255.99);
				frame[idx * 4 + 2] = static_cast<unsigned char>(col.z * 255.99);
				frame[idx * 4 + 3] = 255;
				idx++;
			}
		}


		//write_ppm(frame);

		for (int i = 0; i < width * height; ++i)
		{
			//rgb to bgr for WinForms rendering
			auto b = frame[i * 4];
			frame[i * 4] = frame[i * 4 + 2];
			frame[i * 4 + 2] = b;
		}
	}
}



int main(int argc, char* argv[])
{
	cerr << "Creating image with width " << width << " and height " << height << endl;

	ofstream outfile;
	outfile.open(argv[1]);

	outfile << "P3\n" << width << ' ' << height << "\n255\n";

	unsigned char frame[width * height * 4];
	render(frame);

	for(int i = 0; i < width * height; i++)
	{
		write_color(outfile, frame[i * 4], frame[i * 4 + 1], frame[i * 4 + 2]);
	}
	
	outfile.close();
}
