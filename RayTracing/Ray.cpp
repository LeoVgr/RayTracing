#include "Ray.h"

bool Ray::HitSphere(const Vec3 center, const float radius) const
{
	float a = Dot(direction, direction);
	float b = Dot(direction, origin - center) * 2.0f;
	float c = Dot(origin - center, origin - center) - radius * radius;
	float delta = b * b - 4.0f * a * c;

	return delta > 0;
}

Vec3 Ray::RayColor() const
{
	Vec3 color = Vec3(0, 0, 0);

	float y = direction.Normalized().y;

	//If ray hit a sphere
	if (HitSphere(Vec3(0, 0, -1), 0.5f))
		return Vec3(0.0f, 0.0f, 1.0f);

	//Background color if no collision
	float t = 0.5f * (y + 1); // Keep t between 0 and 1

	Vec3 startingColor = Vec3(0.5f, 0.7f, 1.0f);
	Vec3 endingColor = Vec3(1.0f, 1.0f, 1.0f);
	color = startingColor + (endingColor - startingColor) * t;

	return color;
}

