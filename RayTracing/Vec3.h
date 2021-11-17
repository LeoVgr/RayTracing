#pragma once
#include <math.h>

struct Vec3
{
	float x, y, z;

	Vec3() : x(0.0f),y(0.0f),z(0.0f) {}
	
	Vec3(float p_x, float p_y, float p_z) : x(p_x), y(p_y), z(p_z) {};

	inline Vec3 operator+(const Vec3 p_v) const
	{
		Vec3 v(*this);

		v.x += p_v.x;
		v.y += p_v.y;
		v.z += p_v.z;

		return v;
	}

	inline Vec3 operator-(const Vec3 p_v) const 
	{
		Vec3 v(*this);

		v.x -= p_v.x;
		v.y -= p_v.y;
		v.z -= p_v.z;

		return v;
	}

	inline Vec3 operator*(const float p_scalar) const 
	{
		Vec3 v(*this);

		v.x *= p_scalar;
		v.y *= p_scalar;
		v.z *= p_scalar;

		return v;
	}

	inline Vec3 operator/(const float p_scalar) const
	{		
		Vec3 v(*this);

		v.x /= p_scalar;
		v.y /= p_scalar;
		v.z /= p_scalar;

		return v;
	}

	inline float Length() const
	{
		return sqrt((x*x + y*y + z*z));
	}

	inline Vec3 Normalize()
	{
		return (*this) / Length();
	}

	inline Vec3 Normalized() const
	{
		Vec3 v(*this);
		return Vec3(v / Length());
	}
};

inline float Dot(const Vec3 v1, const Vec3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}