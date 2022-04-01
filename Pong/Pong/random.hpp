#pragma once
#include <random>
#include "Vec2.hpp"

std::default_random_engine generator;
std::uniform_real_distribution<int> distribution(-1, 1);

Vec2 RandomVec2()
{
	Vec2 Output;
	int OutputX = distribution(generator);
	int OutputY = distribution(generator);
	return Output;
}

Vec2 RandomVec2(float x = 0, float y = 0)
{
	Vec2 Output;
	int OutputX = distribution(generator);
	int OutputY = distribution(generator);
	if (x != 0) { OutputX *= x; }
	if (y != 0) { OutputY *= y; }
	return Output;
}