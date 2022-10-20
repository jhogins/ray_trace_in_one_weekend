// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

#include "camera.h"
#include "Color.h"
#include "common.h"
#include "sphere.h"
using namespace std;


const int width = 1920;
const float aspect_ratio = 16.0f / 9.0f;
const int height = static_cast<int>(width / aspect_ratio);
const int samples_per_pixel = 8;

camera cam(aspect_ratio);
vector<shared_ptr<hittable>> hittables;

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


vec3 random_in_unit_sphere() {
	while (true) {
		auto p = vec3::random(-1, 1);
		if (p.length_squared() >= 1) continue;
		return p;
	}
}

int max_recusion_depth = 20;

color ray_color(const ray& r, const int recursion_depth = 0)
{
	//return color(0.0f, 0.0f, 1.0f);
	point3 pt = r.at(1.f);
	color col(/*(pt.x + viewport_width / 2) / viewport_width*/0, 0, (pt.y + .5f) / 1.f);

	float distance = numeric_limits<float>::infinity();
	hit_record rec;
	for (auto hittable : hittables)
	{
		if (hittable->hit(r, 0.0f, 1000.0f, rec) && rec.t < distance)
		{
			distance = rec.t;
			//col = 0.25 * color(rec.normal.x + 1, rec.normal.y + 1, rec.normal.z + 1);

			if (recursion_depth < max_recusion_depth)
			{
				ray bounce(rec.p, rec.normal + random_in_unit_sphere());
				return .5f * ray_color(bounce, recursion_depth + 1);
			}
			else
				return color();
		}
	}

	return col;
}

extern "C" {
	__declspec(dllexport)  int _cdecl get_width() { return width; }
	__declspec(dllexport)  int _cdecl get_height() { return height; }
	__declspec(dllexport)  void _cdecl render(unsigned char* frame)
	{
		hittables.clear();
		hittables.push_back(std::make_shared<sphere>(point3(0, 0, -1.0f), .5f));
		hittables.push_back(std::make_shared<sphere>(point3(2, 1, -5.0f), 1.0f));
		hittables.push_back(std::make_shared<sphere>(point3(2, -1, -3.0f), 1.0f));
		hittables.push_back(std::make_shared<sphere>(point3(0, -100.5f, -1), 100.f));
		

		size_t idx = 0;
		for (size_t y = 0; y < height; y++)
		{
			if (y % 10 == 0)
				std::cerr << "Progress: line " << y << endl;

			for (size_t x = 0; x < width; x++)
			{
				color col;
				for (size_t s = 0; s < samples_per_pixel; s++)
				{
					float u = (x + random_float()) / width;
					float v = (height - y - random_float()) / height;
					ray r = cam.get_ray(u, v);
					col += ray_color(r);
				}
				frame[idx * 4] = static_cast<unsigned char>(col.x / samples_per_pixel * 255.99);
				frame[idx * 4 + 1] = static_cast<unsigned char>(col.y / samples_per_pixel * 255.99);
				frame[idx * 4 + 2] = static_cast<unsigned char>(col.z / samples_per_pixel * 255.99);
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
