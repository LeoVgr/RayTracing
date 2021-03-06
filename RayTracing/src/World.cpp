#include "World.h"

World::~World()
{
	//Free memory of objects stock in the vector
	for (auto object : ObjectList)
	{
		delete object;
	}
	ObjectList.clear();
}

bool World::Hit(const Ray& p_r, float p_tMin, float p_tMax, HitRecord& rec) const
{
	HitRecord tempHitInfo;
	bool hitSomething = false;
	float closestT = p_tMax;

	//Iterate on all scene objects to get the first hit point
	for (auto object : ObjectList)
	{
		if (object->Hit(p_r, p_tMin, closestT, tempHitInfo)) {
			hitSomething = true;
			rec = tempHitInfo;
			closestT = tempHitInfo.T;
		}
	}
	
	return hitSomething;
}
