#include "Vector3.h"
#include <math.h>

CoreVector3::Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

CoreVector3::Vector3::Vector3(const float X, const float Y, const float Z)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

CoreVector3::Vector3::Vector3(const Vector3* a)
{
	this->x = a->x;
	this->y = a->y;
	this->z = a->z;
}

CoreVector3::Vector3 CoreVector3::Vector3::NVector3() 
{
	return *new Vector3();
}

void CoreVector3::Vector3::DVector3()
{
	delete(this);
}

CoreVector3::Vector3 CoreVector3::Min(const Vector3* a, const Vector3* b)
{
	Vector3* c;
	if (a->x <= b->x)
		c->x = a->x;
	else c->x = b->x;
	if (a->y <= b->y)
		c->y = a->y;
	else c->y = b->y;
	if (a->z <= b->z)
		c->z = a->z;
	else c->z = b->z;
	return *c;
}

CoreVector3::Vector3 CoreVector3::Max(const Vector3* a, const Vector3* b)
{
	Vector3* c;
	if (a->x >= b->x)
		c->x = a->x;
	else c->x = b->x;
	if (a->y >= b->y)
		c->y = a->y;
	else c->y = b->y;
	if (a->z >= b->z)
		c->z = a->z;
	else c->z = b->z;
	return *c;
}

void CoreVector3::Clamp(Vector3& a, const float min, const float max)
{
	if (a.x < min)
		a.x = min;
	if (a.x > max)
		a.x = max;
	if (a.y < min)
		a.y = min;
	if (a.y > max)
		a.y = max;
	if (a.z < min)
		a.z = min;
	if (a.z > max)
		a.z = max;
}

CoreVector3::Vector3 CoreVector3::Abs(const Vector3* a)
{
	Vector3* b;
	if (a->x < 0)
		b->x = -a->x;
	else b->x = a->x;
	if (a->y < 0)
		b->y = -a->y;
	else b->y = a->y;
	if (a->z < 0)
		b->z = -a->z;
	else b->z = a->z;
	return *b;
}

float CoreVector3::Magnitude(const Vector3* a) 
{
	return sqrtf((a->x * a->x) + (a->y * a->y) + (a->z * a->z));
}

CoreVector3::Vector3 CoreVector3::Normalize(const Vector3* a)
{
	float m = Magnitude(a);
	return Vector3(a->x / m, a->y / m, a->z / m);
}

float CoreVector3::Dot(const Vector3* a, const Vector3* b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

CoreVector3::Vector3 CoreVector3::Cross(const Vector3* a, const Vector3* b)
{
	return Vector3(a->y * b->z - a->z * b->y, a->z * b->x - a->x * b->z, a->x * b->y - a->y * b->x);
}

float CoreVector3::Distance(const Vector3* a, const Vector3* b)
{
	return Magnitude(a) - Magnitude(b);
}

float CoreVector3::Angle(const Vector3* a, const Vector3* b)
{
	return cosf(Dot(a, b) / (Magnitude(a) * Magnitude(b)));
}

CoreVector3::Vector3 CoreVector3::Lerp(const Vector3* a, const Vector3* b, const float time_to_interpolate)
{
	return *a + (*b - *a) * time_to_interpolate;
}

CoreVector3::Vector3 CoreVector3::Reflect(const Vector3* dir, const Vector3* normal)
{
	Vector3* result;
	float val = 2.0f * (Dot(dir, normal));
	result->x = dir->x - (normal->x * val);
	result->y = dir->y - (normal->y * val);
	result->z = dir->z - (normal->z * val);
	return *result;
}

CoreVector3::Vector3 CoreVector3::ProjectOnScalar(const Vector3* a, const Vector3* b)
{
	return Vector3((*a * *b) / Abs(b));
}

CoreVector3::Vector3 CoreVector3::ProjectOnVector3(const Vector3* a, const Vector3* b)
{
	return Vector3((*a * *b) / (*b * *b) * *b);
}

CoreVector3::Vector3 CoreVector3::Orthoghonal(const Vector3* a, const Vector3* b)
{
	Vector3* cross = &Cross(a, b);
	return Vector3(*cross / Normalize(cross));
}

std::string CoreVector3::ToString(const Vector3* a)
{
	return "X: " + std::to_string(a->x) + ", Y: " + std::to_string(a->y) + ", Z: " + std::to_string(a->z);
}

CoreVector3::Vector3 CoreVector3::Vector2To3(const CoreVector2::Vector2* a, const float Z)
{
	return Vector3(a->x, a->y, Z);
}