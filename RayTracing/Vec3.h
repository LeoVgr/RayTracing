#pragma once

struct Vec3
{
	int x, y, z;

	Vec3() : x(0),y(0),z(0) {}
	
	Vec3(float p_x, float p_y, float p_z) : x(p_x), y(p_y), z(p_z) {};

	Vec3& operator+(const Vec3 v)
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}

	Vec3& operator-(const Vec3 v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}

	Vec3& operator*(const float p_scalar) {

		x *= p_scalar;
		y *= p_scalar;
		z *= p_scalar;

		return *this;
	}
};