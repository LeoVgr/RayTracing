#include "Camera.h"

void Camera::Render()
{
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
				pixelColor = ray.RayColor();

				//Write red blue and green of the current pixel (maybe need to convert it to integer)
				imageData << pixelColor.x * 255 << " " << pixelColor.y * 255 << " " << pixelColor.z * 255 << std::endl;
			}
		}
	}

	//Close the render file
	imageData.close();

}
