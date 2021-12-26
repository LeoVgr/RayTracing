#include "Sphere.h"

bool Sphere::Hit(const Ray& p_r, float p_tMin, float p_tMax, HitRecord& rec) const
{
	//Soluce the quadratic equation
	float a = Dot(p_r.Direction, p_r.Direction);
	float b = Dot(p_r.Origin - Center, p_r.Direction) * 2.0f;
	float c = Dot(p_r.Origin - Center, p_r.Origin - Center) - Radius * Radius;
	float delta = b * b - 4.0f * a * c;

	//No hit
	if (delta < 0)
		return false;

	//Check if the hit point is in the t range
	float sol = (-b - sqrt(delta)) / (2.0f * a);

	if (sol < p_tMin || sol > p_tMax)
	{
		sol = (-b + sqrt(delta)) / (2.0f * a);

		if (sol < p_tMin || sol > p_tMax)
		{
			return false;
		}
	}
	
	//Fill the hit record with hit informations	
	rec.Point = p_r.Origin + p_r.Direction * sol;
	rec.Normal = (rec.Point - Center) / Radius; // We divide by the radius to get an unit vector
	rec.T = sol;
	
}
