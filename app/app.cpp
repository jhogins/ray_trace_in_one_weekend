// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

const int width = 1080;
const int height = 768;


struct vec3
{
public:
	unsigned char x;
	unsigned char y;
	unsigned char z;
} color;



int main(int argc, char* argv[])
{

	cerr << "Creating image with width " << width << " and height " << height << endl;


	ofstream outfile;
	outfile.open(argv[1]);

	outfile << "P3\n" << width << ' ' << height << "\n255\n";
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			auto r = (double)x / width;
			auto g = (double)y / height;
			auto b = .25;

			outfile << (int)(r * 255.99) << " " << (int)(g * 255.99) << " " << (int)(b * 255.99) << "\n";
		}
	}
	outfile.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
