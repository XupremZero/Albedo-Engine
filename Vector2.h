#ifndef Vector2H
#define Vector2H

#include "Vector3.h"

namespace CoreVector2 {
	class Vector2
	{
	public:
		float x, y;

		Vector2();

		Vector2(const float, const float);

		Vector2(const Vector2*);

		Vector2 NVector2();

		void DVector();
	};

	CoreVector2::Vector2 operator+(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		return CoreVector2::Vector2(a.x + b.x, a.y + b.y);
	}

	CoreVector2::Vector2 operator-(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		return CoreVector2::Vector2(a.x - b.x, a.y - b.y);
	}

	CoreVector2::Vector2 operator*(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		return CoreVector2::Vector2(a.x * b.x, a.y * b.y);
	}

	CoreVector2::Vector2 operator/(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		return CoreVector2::Vector2(a.x / b.x, a.y / b.y);
	}

	CoreVector2::Vector2 operator+(const float a, const CoreVector2::Vector2 b)
	{
		return CoreVector2::Vector2(a + b.x, a + b.y);
	}

	CoreVector2::Vector2 operator-(const float a, const CoreVector2::Vector2 b)
	{
		return CoreVector2::Vector2(a - b.x, a - b.y);
	}

	CoreVector2::Vector2 operator*(const float a, const CoreVector2::Vector2 b)
	{
		return CoreVector2::Vector2(a * b.x, a * b.y);
	}

	CoreVector2::Vector2 operator/(const float a, const CoreVector2::Vector2 b)
	{
		return CoreVector2::Vector2(a / b.x, a / b.y);
	}

	CoreVector2::Vector2 operator+(const CoreVector2::Vector2 a, const float b)
	{
		return CoreVector2::Vector2(a.x + b, a.y + b);
	}

	CoreVector2::Vector2 operator-(const CoreVector2::Vector2 a, const float b)
	{
		return CoreVector2::Vector2(a.x - b, a.y - b);
	}

	CoreVector2::Vector2 operator*(const CoreVector2::Vector2 a, const float b)
	{
		return CoreVector2::Vector2(a.x * b, a.y * b);
	}

	CoreVector2::Vector2 operator/(const CoreVector2::Vector2 a, const float b)
	{
		return CoreVector2::Vector2(a.x / b, a.y / b);
	}

	CoreVector2::Vector2 operator++(const CoreVector2::Vector2 a)
	{
		return CoreVector2::Vector2(a.x + 1, a.y + 1);
	}

	CoreVector2::Vector2 operator--(const CoreVector2::Vector2 a)
	{
		return CoreVector2::Vector2(a.x - 1, a.y - 1);
	}

	static const float Epsilon = 0.0000001f;

	bool operator==(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		if ((a.x - b.x) <= Epsilon && (a.y - b.y) <= Epsilon)
			return true;
		else return false;
	}

	bool operator!=(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		if ((a.x - b.x) > Epsilon && (a.y - b.y) > Epsilon)
			return true;
		else return false;
	}

	Vector2 operator+=(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		return Vector2(a + b);
	}

	Vector2 operator-=(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		return Vector2(a - b);
	}

	Vector2 operator*=(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		return Vector2(a * b);
	}

	Vector2 operator/=(const CoreVector2::Vector2 a, const CoreVector2::Vector2 b)
	{
		return Vector2(a / b);
	}

	Vector2 Abs(const Vector2*);

	float Magnitude(const Vector2*);
	
	Vector2 Normalize(const Vector2*);

	float Dot(const CoreVector2::Vector2*, const CoreVector2::Vector2*);

	float Distance(const Vector2*, const Vector2*);

	float Angle(const Vector2*, const Vector2*);

	Vector2 Lerp(const Vector2*, const Vector2*, const float);

	void Clamp(Vector2&, float, float);

	Vector2 Rotate(const Vector2*, const float);

	Vector2 Min(const Vector2*, const Vector2*);

	Vector2 Max(const Vector2*, const Vector2*);

	void MoveToward(Vector2&, const Vector2*, const float);

	Vector2 Reflect(const Vector2*, const Vector2*);

	std::string ToString(const Vector2*);

	Vector2 Vector3To2(const CoreVector3::Vector3*);
}

#endif