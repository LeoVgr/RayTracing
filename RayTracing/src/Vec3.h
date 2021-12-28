#pragma once
#include <math.h>
#include "Utility.h"

struct Vec3
{
	float X, Y, Z;

	Vec3() : X(0.0f),Y(0.0f),Z(0.0f) {}
	
	Vec3(float x, float y, float z) : X(x), Y(y), Z(z) {};

	inline Vec3 operator+(const Vec3 u) const
	{
		Vec3 v(this->X, this->Y, this->Z);

		v.X += u.X;
		v.Y += u.Y;
		v.Z += u.Z;

		return v;
	}

	inline Vec3 operator-(const Vec3 u) const 
	{
		Vec3 v(this->X, this->Y, this->Z);

		v.X -= u.X;
		v.Y -= u.Y;
		v.Z -= u.Z;

		return v;
	}

	inline Vec3 operator*(const float scalar) const 
	{
		Vec3 v(this->X, this->Y, this->Z);

		v.X *= scalar;
		v.Y *= scalar;
		v.Z *= scalar;

		return v;
	}

	inline Vec3 operator/(const float scalar) const
	{		
		Vec3 v(this->X, this->Y, this->Z);

		v.X /= scalar;
		v.Y /= scalar;
		v.Z /= scalar;

		return v;
	}

	inline float Length() const
	{
		return sqrt((X*X + Y*Y + Z*Z));
	}

	inline Vec3 Normalize()
	{
		return (*this) / Length();
	}

	inline Vec3 Normalized() const
	{
		Vec3 v(this->X, this->Y, this->Z);
		return Vec3(v / Length());
	}

	inline float static Dot(const Vec3 v, const Vec3 u)
	{
		return v.X * u.X + v.Y * u.Y + v.Z * u.Z;
	}

	inline static Vec3 Random()
	{
		return Vec3(RandomFloat(), RandomFloat(), RandomFloat());
	}

	inline static Vec3 Random(float min, float max)
	{
		return Vec3(RandomFloat(min, max), RandomFloat(min, max), RandomFloat(min, max));
	}

	static Vec3 RandomInUnitSphere()
	{
		while (true) {
			Vec3 p = Vec3::Random(-1, 1);
			if (p.X * p.X + p.Y * p.Y + p.Z * p.Z >= 1) continue;
			return p;
		}
	}

	static Vec3 RandomUnitVector() {
		return RandomInUnitSphere().Normalize();
	}

	static Vec3 RandomInHemisphere(const Vec3& normal) {
		Vec3 inUnitSphere = RandomInUnitSphere();
		if (Vec3::Dot(inUnitSphere, normal) > 0.0) // In the same hemisphere as the normal
			return inUnitSphere;
		else
			return inUnitSphere * (- 1);
	}
};



