#pragma once
#include <math.h>

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
};

inline float Dot(const Vec3 v, const Vec3 u)
{
	return v.X * u.X + v.Y * u.Y + v.Z * u.Z;
}