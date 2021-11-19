#include "Ray.h"


Vec3 Ray::RayColor() const
{
	//Initialize the color of the pixel
	Vec3 color = Vec3(0, 0, 0);

	//We get the y of the point
	float y = direction.Normalized().y;

	//We add a sphere in our scene
	Sphere sphere = Sphere(Vec3(0.0f,0.0f,0.0f), 0.5f);
	HitRecord hit = HitRecord();

	if (sphere.Hit(*this, 0.0f ,100.0f , hit))
		return Vec3(hit.normal.x + 1, hit.normal.y + 1, hit.normal.z + 1) * 0.5f;

	//Background color if no collision
	float t = 0.5f * (y + 1); // Keep t between 0 and 1

	Vec3 startingColor = Vec3(0.5f, 0.7f, 1.0f);
	Vec3 endingColor = Vec3(1.0f, 1.0f, 1.0f);
	color = startingColor + (endingColor - startingColor) * t;

	return color;
}

