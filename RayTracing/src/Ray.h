#pragma once

#include "Vec3.h"

class Ray 
{
public :
	Vec3 Origin;
	Vec3 Direction;

	Ray() : Origin(Vec3(0.0f, 0.0f, 0.0f)), Direction(Vec3(0.0f, 0.0f, 0.0f)) {};
	Ray(Vec3 origin, Vec3 direction) : Origin(origin), Direction(direction) {};

};