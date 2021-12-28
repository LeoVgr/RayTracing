#pragma once
#include <random>

inline float Clamp(float x, float min, float max)
{
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

inline float RandomFloat()
{
	//Returns a random real in [0,1).
	return rand() / (RAND_MAX + 1.0f);
}

inline float RandomFloat(float min, float max) {
	//Returns a random real in [min,max).
	return min + (max - min) * RandomFloat();
}