#pragma once
#include <vector>
#include "Hittable.h"

class World
{
	public:
		std::vector<Hittable*> objectList;

	public:
		World() {}
		~World();

	public:
		bool Hit(const Ray& p_r, float p_tMin, float p_tMax, HitRecord& rec) const;




};

