#pragma once

#include "Vec3.h"

class Ray 
{
	public :
		Vec3 origin;
		Vec3 direction;

	public :
		Ray(Vec3 p_origin, Vec3 p_direction) : origin(p_origin), direction(p_direction) {};
		bool HitSphere(const Vec3 center, const float radius) const;
		Vec3 RayColor() const;


};