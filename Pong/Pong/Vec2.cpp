#include "Vec2.hpp"

Vec2::Vec2(float xin, float yin)
	:x(xin), y(yin) {}

Vec2::Vec2(int xin, int yin)
	: x(static_cast<float>(xin)), y(static_cast<float>(yin)) {}

Vec2 Vec2::operator+(const Vec2& rhs) { return Vec2(x + rhs.x, y + rhs.y); }
Vec2 Vec2::operator/(float scalar) { return Vec2(x /= scalar, y /= scalar); }
Vec2 Vec2::operator+=(const Vec2& rhs) 
{ 
    x += rhs.x;
    y += rhs.y;
    return *this;
}
Vec2 Vec2::operator-=(const Vec2& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}
bool Vec2::operator==(const Vec2& rhs) { return (x == rhs.x) && (y == rhs.y); }
Vec2 Vec2::operator*(const Vec2& rhs) { return Vec2(x * rhs.x, y * rhs.y); }
Vec2 Vec2::operator*(float scalar) {     return Vec2(x *= scalar, y *= scalar); }
Vec2 Vec2::operator*=(float scalar) 
{    
    x *= scalar;
    y *= scalar;
    return *this;
}
Vec2& Vec2::scale(float scale) 
{ 
    x *= scale; 
    y *= scale;
    return *this;
}
Vec2& Vec2::add(float val) { x += val; y += val; return *this; }

float Vec2::distance(const Vec2& rhs)
{
    float xsq = powf((rhs.x - x), 2);
    float ysq = powf((rhs.y - y), 2);
    float dist = sqrt(xsq + ysq);
    return dist;
}

float Vec2::distanceSq(const Vec2& rhs)
{
    float xsq = (rhs.x - x) * (rhs.x -x);
    float ysq = (rhs.y - y) * (rhs.y -y);
    float dist = xsq + ysq;
    return dist;
}


Vec2& Vec2::normalise(const Vec2& rhs)
{
    float dist = distance(rhs);
    Vec2 norm;
    norm.x = rhs.x / dist;
    norm.y = rhs.y / dist;
    return norm;
}

static float Dot(const Vec2& a, const Vec2& b)
{
    return (a.x * b.x + a.y * b.y);
}

std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
{
    return stream << vector.x << " " << vector.y << "\n";
}
void Vec2::print()
{
    std::cout << "(" << x << " , " << y << ")" << "\n";
}
