#pragma once
#include <vector>
#include "Hittable.h"

class World
{
public:
	std::vector<Hittable*> ObjectList;

	World() {}
	~World();
	bool Hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const;

};

