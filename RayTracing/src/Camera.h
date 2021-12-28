#pragma once
#include <iostream>
#include <fstream>
#include "Ray.h"
#include "World.h"
#include "Utility.h"


class Camera
{
public:
	//Image
	const float IMAGE_RATIO = 16.0f / 9.0f;
	const int IMAGE_WIDTH = 700;
	const int IMAGE_HEIGHT = static_cast<int>(float(IMAGE_WIDTH) / float(IMAGE_RATIO));
	const int SAMPLE_PER_PIXEL = 100;

	float ViewportHeight = 2.0f;
	float ViewportWidth = ViewportHeight * IMAGE_RATIO;
	float FocalLength = 1.0f;
	Vec3 Origin = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 Position;
	Vec3 Horizontal = Vec3(ViewportWidth, 0.0f, 0.0f);
	Vec3 Vertical = Vec3(0.0f, ViewportHeight, 0.0f);
	Vec3 LowerLeftCorner = Origin - Vec3(0.0f, 0.0f, FocalLength) - Horizontal / 2.0f - Vertical / 2.0f;	
		
	Camera() : Position(0,0,0) {}
	void Render(World& world);
	void WriteColor(std::ostream &out, Vec3 color, int SamplePerPixel);
	Vec3 RayColor(Ray& r, World& world) const;
};