#pragma once
#include <iostream>
#include <fstream>
#include "Ray.h"
#include "World.h"


class Camera
{
	public:
		const float IMAGE_RATIO = 16.0f / 9.0f;
		const int IMAGE_WIDTH = 700;
		const int IMAGE_HEIGHT = static_cast<int>(float(IMAGE_WIDTH) / float(IMAGE_RATIO));

		float viewportHeight = 2;
		float viewportWidth = viewportHeight * IMAGE_RATIO;
		float focalLength = 1;

		Vec3 origin = Vec3(0.0f, 0.0f, 0.0f);
		Vec3 horizontal = Vec3(viewportWidth, 0.0f, 0.0f);
		Vec3 vertical = Vec3(0.0f, viewportHeight, 0.0f);
		Vec3 lowerLeftCorner = origin - Vec3(0.0f, 0.0f, focalLength) - horizontal / 2 - vertical / 2;

	public:
		Vec3 position;
		
	public :
		Camera() : position(0,0,0) {}

		void Render(World& world);
		Vec3 RayColor(Ray& r, World& world) const;

	
};