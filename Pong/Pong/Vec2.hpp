#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vec2
{
public:
	float x;
	float y;
	Vec2(float x, float y);
	Vec2(int x, int y);
	Vec2() {
		x = 0;
		y = 0;
	}

	Vec2 operator+(const Vec2& rhs);
	friend Vec2 operator-(const Vec2& a, const Vec2& b)
	{
		return Vec2(a.x - b.x, a.y - b.y);
	}
	Vec2 operator+=(const Vec2& rhs);
	Vec2 operator-=(const Vec2& rhs);
	bool operator==(const Vec2& rhs);
	Vec2 operator*(const Vec2& rhs);
	Vec2 operator*(float scalar);
	Vec2 operator*=(float scalar);
	Vec2 operator/(float scalar);
	//TO DO:
	// += -= *= /= / != NORMALISE
	Vec2& scale(float scale);
	Vec2& add(float val);

	static float Dot(const Vec2& a, const Vec2& b);

	Vec2& normalise(const Vec2& rhs);

	float distance(const Vec2& rhs);
	float distanceSq(const Vec2& rhs);

	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);

	void print();
};

#endif
