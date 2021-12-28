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

				for (int s = 0; s < SAMPLE_PER_PIXEL; ++s)
				{
					float u = float(x + RandomFloat()) / float((IMAGE_WIDTH - 1));
					float v = float(y + RandomFloat()) / float((IMAGE_HEIGHT - 1));

					Ray ray(Origin, LowerLeftCorner + Horizontal * u + Vertical * v - Origin);
					pixelColor = pixelColor + RayColor(ray, world, MAX_DEPTH);
				}		

				WriteColor(imageData, pixelColor, SAMPLE_PER_PIXEL);
			}
		}
	}

	//Close the render file
	imageData.close();

	std::cerr << "\nDone."<< std::flush;
}

void Camera::WriteColor(std::ostream& out, Vec3 color, int SamplePerPixel)
{
	float r = color.X;
	float g = color.Y;
	float b = color.Z;

	// Divide the color by the number of samples.
	float scale = 1.0f / (float)SamplePerPixel;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);

	// Write the translated [0,255] value of each color component.
	out << static_cast<int>(256 * Clamp(r, 0.0f, 0.999f)) << ' '
		<< static_cast<int>(256 * Clamp(g, 0.0f, 0.999f)) << ' '
		<< static_cast<int>(256 * Clamp(b, 0.0f, 0.999f)) << '\n';
}

Vec3 Camera::RayColor(Ray& r, World& world, int depth) const
{
	//Initialize the color of the pixel
	Vec3 color = Vec3(0, 0, 0);

	// If we've exceeded the ray bounce limit, no more light is gathered.
	if (depth <= 0)
		return color;

	//Check if there is a collision with an hittable in the world
	HitRecord hitInfo;
	if (world.Hit(r, 0.001f, 1000.0f, hitInfo))
	{
		Vec3 target = hitInfo.Point + Vec3::RandomInHemisphere(hitInfo.Normal);
		//Vec3 target = hitInfo.Point + hitInfo.Normal + Vec3::RandomInUnitSphere();
		Ray bounce = Ray(hitInfo.Point, target - hitInfo.Point);
		return RayColor(bounce, world, depth -1) * 0.5f;
	}

	//Background color if no collision
	//We get the y of the point
	float y = r.Direction.Normalized().Y;
	float t = 0.5f * (y + 1); // Keep t between 0 and 1

	Vec3 startingColor = Vec3(0.5f, 0.7f, 1.0f);
	Vec3 endingColor = Vec3(1.0f, 1.0f, 1.0f);
	color = startingColor + (endingColor - startingColor) * t;

	return color;
}

