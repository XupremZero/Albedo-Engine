#ifndef Vector3H
#define Vector3H

#include <string>
#include "Vector2.h"

namespace CoreVector3 {
	class Vector3
	{
	public:
		float x, y, z;

		Vector3();

		Vector3(const float, const float, const float);

		Vector3(const Vector3*);

		Vector3 NVector3();

		void DVector3();
	};

	Vector3 operator+(const Vector3 a, const Vector3 b)
	{
		return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	Vector3 operator-(const Vector3 a, const Vector3 b)
	{
		return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
	}

	Vector3 operator*(const Vector3 a, const Vector3 b)
	{
		return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
	}

	Vector3 operator/(const Vector3 a, const Vector3 b)
	{
		return Vector3(a.x / b.x, a.y / b.y, a.z / b.z);
	}

	Vector3 operator+(const float a, const Vector3 b)
	{
		return Vector3(a + b.x, a + b.y, a + b.z);
	}

	Vector3 operator-(const float a, const Vector3 b)
	{
		return Vector3(a - b.x, a - b.y, a - b.z);
	}

	Vector3 operator*(const float a, const Vector3 b)
	{
		return Vector3(a * b.x, a * b.y, a * b.z);
	}

	Vector3 operator/(const float a, const Vector3 b)
	{
		return Vector3(a / b.x, a / b.y, a / b.z);
	}

	Vector3 operator+(const Vector3 a, const float b)
	{
		return Vector3(a.x + b, a.y + b, a.z + b);
	}

	Vector3 operator-(const Vector3 a, const float b)
	{
		return Vector3(a.x - b, a.y - b, a.z - b);
	}

	Vector3 operator*(const Vector3 a, const float b)
	{
		return Vector3(a.x * b, a.y * b, a.z * b);
	}

	Vector3 operator/(const Vector3 a, const float b)
	{
		return Vector3(a.x / b, a.y / b, a.z / b);
	}

	Vector3 operator+=(const Vector3 a, const Vector3 b)
	{
		return Vector3(a + b);
	}

	Vector3 operator-=(const Vector3 a, const Vector3 b)
	{
		return Vector3(a - b);
	}

	Vector3 operator*=(const Vector3 a, const Vector3 b)
	{
		return Vector3(a * b);
	}

	Vector3 operator/=(const Vector3 a, const Vector3 b)
	{
		return Vector3(a / b);
	}

	Vector3 Abs(const Vector3*);

	Vector3 Min(const Vector3*, const Vector3*);

	Vector3 Max(const Vector3*, const Vector3*);

	void Clamp(Vector3&, const float, const float);

	float Magnitude(const Vector3*);
	
	Vector3 Normalize(const Vector3*);

	float Dot(const Vector3*, const Vector3*);

	Vector3 Cross(const Vector3*, const Vector3*);

	float Distance(const Vector3*, const Vector3*);

	float Angle(const Vector3*, const Vector3*);

	Vector3 Lerp(const Vector3*, const Vector3*, const float);

	Vector3 Slerp(const Vector3*, const Vector3*);

	Vector3 Reflect(const Vector3*, const Vector3*);

	Vector3 ProjectOnScalar(const Vector3*, const Vector3*);

	Vector3 ProjectOnVector3(const Vector3*, const Vector3*);

	Vector3 Orthoghonal(const Vector3*, const Vector3*);

	std::string ToString(const Vector3*);

	Vector3 Vector2To3(const CoreVector2::Vector2*, const float);
}

#endif