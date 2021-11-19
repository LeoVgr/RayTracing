#pragma once

#include "Hittable.h"

class Sphere : public Hittable
{
	public:
		Vec3 center;
		float radius;
	
	public :
		Sphere() : center(Vec3(0, 0, 0)), radius(0.5f) {}
		Sphere(Vec3 p_center, float p_radius) : center(p_center), radius(p_radius) {}

	public :
		virtual bool Hit(const Ray& p_r, float p_tMin, float p_tMax, HitRecord& rec) const override;
};