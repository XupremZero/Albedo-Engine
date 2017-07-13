#include "Vector2.h"
#include <math.h>
#include "MathUtils.h"

CoreVector2::Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

CoreVector2::Vector2::Vector2(const float X, const float Y)
{
	this->x = X;
	this->y = Y;
}

CoreVector2::Vector2::Vector2(const Vector2* a)
{
	this->x = a->x;
	this->y = a->y;
}

CoreVector2::Vector2 CoreVector2::Vector2::NVector2()
{
	return *new Vector2();
}

void CoreVector2::Vector2::DVector()
{
	delete(this);
}

CoreVector2::Vector2 CoreVector2::Abs(const Vector2* a)
{
	Vector2* b;
	if (a->x < 0)
		b->x = -a->x;
	else b->x = a->x;
	if (a->y < 0)
		b->y = -a->y;
	else b->y = a->y;
	return *b;
}

float CoreVector2::Magnitude(const CoreVector2::Vector2* a)
{
	return sqrtf((a->x * a->x) + (a->y * a->y));
}

CoreVector2::Vector2 CoreVector2::Normalize(const Vector2* a)
{
	float m = Magnitude(a);	
	return Vector2(a->x / m, a->y / m);
}

float CoreVector2::Dot(const CoreVector2::Vector2* a, const CoreVector2::Vector2* b)
{
	return a->x * b->x + a->y * b->y;
}

float CoreVector2::Distance(const CoreVector2::Vector2* a, const CoreVector2::Vector2* b)
{
	return Magnitude(a) - Magnitude(b);
}

float CoreVector2::Angle(const CoreVector2::Vector2* a, const CoreVector2::Vector2* b)
{
	return cosf(Dot(a, b) / (Magnitude(a) * Magnitude(b)));
}

CoreVector2::Vector2 CoreVector2::Lerp(const CoreVector2::Vector2* a, const CoreVector2::Vector2* b, const float time_to_interpolate)
{
	return *a + (*b - *a) * time_to_interpolate;
}

void CoreVector2::Clamp(CoreVector2::Vector2& a, float min, float max)
{
	if (a.x < min)
		a.x = min;
	if (a.x > max)
		a.x = max;
	if (a.y < min)
		a.y = min;
	if (a.y > max)
		a.y = max;
}

CoreVector2::Vector2 CoreVector2::Rotate(const CoreVector2::Vector2* a, const float angle)
{
	
	float rad = angle * CoreMath::ToRadians;
	float cos = cosf(rad);
	float sin = sinf(rad);
	return CoreVector2::Vector2(a->x * cos - a->y * sin, a->x * sin + a->y * cos);
}

CoreVector2::Vector2 CoreVector2::Min(const CoreVector2::Vector2* a, const CoreVector2::Vector2* b)
{
	Vector2* c;
	if (a->x <= b->x)
		c->x = a->x;
	else c->x = b->x;
	if (a->y <= b->y)
		c->y = a->y;
	else c->y = b->y;
	return *c;
}

CoreVector2::Vector2 CoreVector2::Max(const CoreVector2::Vector2* a, const CoreVector2::Vector2* b)
{
	Vector2* c;
	if (a->x >= b->x)
		c->x = a->x;
	else c->x = b->x;
	if (a->y >= b->y)
		c->y = a->y;
	else c->y = b->y;
	return *c;
}

void CoreVector2::MoveToward(CoreVector2::Vector2& this_position, const CoreVector2::Vector2* target, const float MaxDistance)
{
	Vector2* c;
	c->x = target->x - this_position.x;
	c->y = target->y - this_position.y;
	float hyp = Magnitude(c);
	c->x /= hyp;
	c->y /= hyp;
	this_position.x += c->x;
	this_position.y += c->y;
}

CoreVector2::Vector2 CoreVector2::Reflect(const Vector2* dir, const Vector2* normal)
{
	Vector2* result;
	float val = 2.0f * (Dot(dir, normal));
	result->x = dir->x - (normal->x * val);
	result->y = dir->y - (normal->y * val);
	return *result;
}

std::string CoreVector2::ToString(const Vector2* a)
{
	return "X: " + std::to_string(a->x) + ", Y: " + std::to_string(a->y);
}

CoreVector2::Vector2 CoreVector2::Vector3To2(const CoreVector3::Vector3* a)
{
	return Vector2(a->x, a->y);
}