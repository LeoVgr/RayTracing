#include "Camera.h"

void Camera::Render(World& world)
{
	//Open the render file
	std::ofstream imageData;
	imageData.open("image.ppm");

	//Render in ppm image format
	if (imageData.is_open())
	{
		//Header of a ppm image file
		imageData << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

		for (int y = IMAGE_HEIGHT - 1; y >= 0; --y) //We start from IMAGE_HEIGHT because we want to write topleft color first in ppm format
		{
			std::cerr << "\rScanlines remaining : " << y << ' ' << std::flush;
			for (int x = 0; x < IMAGE_WIDTH; ++x)
			{
				Vec3 pixelColor = Vec3(0.0f, 0.0f, 0.0f);

				float u = float(x) / float((IMAGE_WIDTH - 1));
				float v = float(y) / float((IMAGE_HEIGHT - 1));

				Ray ray(Origin, LowerLeftCorner + Horizontal * u + Vertical * v - Origin);
				pixelColor = RayColor(ray, world);

				//Write red blue and green of the current pixel (maybe need to convert it to integer)
				imageData << pixelColor.X * 255 << " " << pixelColor.Y * 255 << " " << pixelColor.Z * 255 << std::endl;			
			}
		}
	}

	//Close the render file
	imageData.close();

	std::cerr << "\nDone."<< std::flush;
}

Vec3 Camera::RayColor(Ray& r, World& world) const
{
	//Initialize the color of the pixel
	Vec3 color = Vec3(0, 0, 0);

	//We get the y of the point
	float y = r.Direction.Normalized().Y;

	//Check if there is a collision with an hittable in the world
	HitRecord hitInfo;
	if (world.Hit(r, 0, 1000, hitInfo))
		return Vec3(hitInfo.Normal.X + 1, hitInfo.Normal.Y + 1, hitInfo.Normal.Z + 1) * 0.5f;

	//Background color if no collision
	float t = 0.5f * (y + 1); // Keep t between 0 and 1

	Vec3 startingColor = Vec3(0.5f, 0.7f, 1.0f);
	Vec3 endingColor = Vec3(1.0f, 1.0f, 1.0f);
	color = startingColor + (endingColor - startingColor) * t;

	return color;
}

