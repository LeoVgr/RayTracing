#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Vec3.h"
#include "Ray.h"

Vec3 RayColor(const Ray ray)
{
	Vec3 color = Vec3(0, 0, 0);

	float y = ray.direction.Normalized().y;

	//Background color if no collision
	float t = 0.5f * (y + 1); // Keep t between 0 and 1

	Vec3 startingColor = Vec3(0.5f, 0.7f, 1.0f);
	Vec3 endingColor = Vec3(1.0f, 1.0f, 1.0f);
	color = startingColor + (endingColor - startingColor) * t;

	return color;
}


int main()
{
	//Image
	const float IMAGE_RATIO = 16.0f / 9.0f;
	const int IMAGE_WIDTH = 700;
	const int IMAGE_HEIGHT = static_cast<int>(float(IMAGE_WIDTH) / float(IMAGE_RATIO));
	
	//Camera
	float viewportHeight = 2;
	float viewportWidth = viewportHeight * IMAGE_RATIO;
	float focalLength = 1;

	Vec3 origin = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 horizontal = Vec3(viewportWidth, 0.0f, 0.0f);
	Vec3 vertical = Vec3(0.0f, viewportHeight, 0.0f);
	Vec3 lowerLeftCorner = origin - Vec3(0.0f, 0.0f, focalLength) - horizontal / 2 - vertical / 2;

	//Open the render file
	std::ofstream imageData;
	imageData.open("image.ppm");

	//Render in ppm image format
	if (imageData.is_open())
	{
		//Header of a ppm image file
		imageData << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

		for (int y = 0; y < IMAGE_HEIGHT; ++y)
		{
			std::cerr << "\rScanlines remaining : " << y << ' ' << std::flush;
			for (int x = 0; x < IMAGE_WIDTH; ++x)
			{
				Vec3 pixelColor = Vec3(0.0f, 0.0f, 0.0f);

				float u = float(x) / float((IMAGE_WIDTH - 1));
				float v = float(y) / float((IMAGE_HEIGHT - 1));

				Ray ray(origin, (lowerLeftCorner + horizontal * u + vertical * v) - origin);
				pixelColor = RayColor(ray);

				//Write red blue and green of the current pixel (maybe need to convert it to integer)
				imageData << pixelColor.x * 255 << " " << pixelColor.y * 255 << " " << pixelColor.z * 255 << std::endl;
			}
		}
	}
	
	//Close the render file
	imageData.close();	
}

