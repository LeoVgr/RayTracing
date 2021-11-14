#include <iostream>
#include <fstream>
#include <stdio.h>


int main() {

	const int IMAGE_WIDTH = 256;
	const int IMAGE_HEIGHT = 256;
	
	//Open the render file
	std::ofstream imageData;
	imageData.open("image.ppm");

	//Render in ppm image format
	if (imageData.is_open())
	{
		//Header of a ppm image file
		imageData << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

		for (int x = 0; x < IMAGE_WIDTH; ++x)
		{
			std::cerr << "\rScanlines remaining : " << x << ' ' << std::flush;
			for (int y = 0; y < IMAGE_HEIGHT; ++y)
			{
				//Colors of the current pixel
				float r = x;
				float g = y;
				float b = 100;

				//Write red blue and green of the current pixel (maybe need to convert it to integer)
				imageData << r << " " << g << " " << b << std::endl;
			}
		}
	}
	
	//Close the render file
	imageData.close();
	
}