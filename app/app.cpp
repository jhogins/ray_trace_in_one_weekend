// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "vec3.h"
#include "Color.h"
using namespace std;

const int width = 1080;
const int height = 768;



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
			color col((double)x / width, (double)y / height, .25);
			write_color(outfile, col);
		}
	}
	outfile.close();
}