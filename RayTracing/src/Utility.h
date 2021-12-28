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
	return rand() / (RAND_MAX + 1.0f);
}