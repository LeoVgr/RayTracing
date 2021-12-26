#pragma once

#include "Hittable.h"

class Sphere : public Hittable
{
public:
	Vec3 Center;
	float Radius;

	Sphere() : Center(Vec3(0, 0, 0)), Radius(0.5f) {}
	Sphere(Vec3 center, float radius) : Center(center), Radius(radius) {}
	virtual bool Hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;
};