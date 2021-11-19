#pragma once

#include "Ray.h"

struct HitRecord
{
	Vec3 point;
	Vec3 normal;
	float t;
};

class Hittable
{
	public:
		virtual bool Hit(const Ray& p_r, float p_tMin, float p_tMax, HitRecord& rec) const = 0;		
};