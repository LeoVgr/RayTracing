#pragma once

#include "Vec3.h"
#include "Sphere.h"

class Ray 
{
	public :
		Vec3 origin;
		Vec3 direction;

	public :
		Ray() : origin(Vec3(0.0f, 0.0f, 0.0f)), direction(Vec3(0.0f, 0.0f, 0.0f)) {};
		Ray(Vec3 p_origin, Vec3 p_direction) : origin(p_origin), direction(p_direction) {};

	public:
		Vec3 RayColor() const;


};