#pragma once

#include "Ray.h"

struct HitRecord
{
	Vec3 Point;
	Vec3 Normal;
	float T;
};

class Hittable
{
public:
	virtual bool Hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const = 0;		
};