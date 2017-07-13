#ifndef Matrix9H
#define Matrix9H

namespace CoreMatrix9 {
	class Matrix9
	{
	public:
		float m[3][3];

		Matrix9();

		Matrix9(const float, const float, const float, const float, const float, const float, const float, const float, const float);
	
		Matrix9(const float[9]);

		Matrix9(const Matrix9*);

		Matrix9 NMatrix9();

		void DMatrix9();
	};

	const Matrix9 Identity(1, 0, 0, 0, 1, 0, 0, 0, 1);

	Matrix9 operator+(const Matrix9 a, const float b)
	{
		return Matrix9(a.m[0][0] + b, a.m[0][1] + b, a.m[0][2] + b, a.m[1][0] + b, a.m[1][1] + b, a.m[1][2] + b, a.m[2][0] + b, a.m[2][1] + b, a.m[2][2] + b);
	}

	Matrix9 operator-(const Matrix9 a, const float b)
	{
		return Matrix9(a.m[0][0] - b, a.m[0][1] - b, a.m[0][2] - b, a.m[1][0] - b, a.m[1][1] - b, a.m[1][2] - b, a.m[2][0] - b, a.m[2][1] - b, a.m[2][2] - b);
	}

	Matrix9 operator*(const Matrix9 a, const float b)
	{
		return Matrix9(a.m[0][0] * b, a.m[0][1] * b, a.m[0][2] * b, a.m[1][0] * b, a.m[1][1] * b, a.m[1][2] * b, a.m[2][0] * b, a.m[2][1] * b, a.m[2][2] * b);
	}

	Matrix9 operator/(const Matrix9 a, const float b)
	{
		return Matrix9(a.m[0][0] / b, a.m[0][1] / b, a.m[0][2] / b, a.m[1][0] / b, a.m[1][1] / b, a.m[1][2] / b, a.m[2][0] / b, a.m[2][1] / b, a.m[2][2] / b);
	}

	Matrix9 operator+(const float a, const Matrix9 b)
	{
		return Matrix9(a + b.m[0][0], a + b.m[0][1], a + b.m[0][2], a + b.m[1][0], a + b.m[1][1], a + b.m[1][2], a + b.m[2][0], a + b.m[2][1], a + b.m[2][2]);
	}

	Matrix9 operator-(const float a, const Matrix9 b)
	{
		return Matrix9(a - b.m[0][0], a - b.m[0][1], a - b.m[0][2], a - b.m[1][0], a - b.m[1][1], a - b.m[1][2], a - b.m[2][0], a - b.m[2][1], a - b.m[2][2]);
	}

	Matrix9 operator*(const float a, const Matrix9 b)
	{
		return Matrix9(a * b.m[0][0], a * b.m[0][1], a * b.m[0][2], a * b.m[1][0], a * b.m[1][1], a * b.m[1][2], a * b.m[2][0], a * b.m[2][1], a * b.m[2][2]);
	}

	Matrix9 operator/(const float a, const Matrix9 b)
	{
		return Matrix9(a / b.m[0][0], a / b.m[0][1], a / b.m[0][2], a / b.m[1][0], a / b.m[1][1], a / b.m[1][2], a / b.m[2][0], a / b.m[2][1], a / b.m[2][2]);
	}

	Matrix9 operator+(const Matrix9 a, const Matrix9 b)
	{
		return Matrix9(a.m[0][0] + b.m[0][0], a.m[0][1] + b.m[0][1], a.m[0][2] + b.m[0][2], a.m[1][0] + b.m[1][0], a.m[1][1] + b.m[1][1], a.m[1][2] + b.m[1][2], a.m[2][0] + b.m[2][0], a.m[2][1] + b.m[2][1], a.m[2][2] + b.m[2][2]);
	}

	Matrix9 operator-(const Matrix9 a, const Matrix9 b)
	{
		return Matrix9(a.m[0][0] - b.m[0][0], a.m[0][1] - b.m[0][1], a.m[0][2] - b.m[0][2], a.m[1][0] - b.m[1][0], a.m[1][1] - b.m[1][1], a.m[1][2] - b.m[1][2], a.m[2][0] - b.m[2][0], a.m[2][1] - b.m[2][1], a.m[2][2] - b.m[2][2]);
	}

	Matrix9 operator*(const Matrix9 a, const Matrix9 b)
	{
		return Matrix9(a.m[0][0] * b.m[0][0], a.m[0][1] * b.m[0][1], a.m[0][2] * b.m[0][2], a.m[1][0] * b.m[1][0], a.m[1][1] * b.m[1][1], a.m[1][2] * b.m[1][2], a.m[2][0] * b.m[2][0], a.m[2][1] * b.m[2][1], a.m[2][2] * b.m[2][2]);
	}

	Matrix9 operator/(const Matrix9 a, const Matrix9 b)
	{
		return Matrix9(a.m[0][0] / b.m[0][0], a.m[0][1] / b.m[0][1], a.m[0][2] / b.m[0][2], a.m[1][0] / b.m[1][0], a.m[1][1] / b.m[1][1], a.m[1][2] / b.m[1][2], a.m[2][0] / b.m[2][0], a.m[2][1] / b.m[2][1], a.m[2][2] / b.m[2][2]);
	}

	Matrix9 Transpose(const Matrix9*);

	Matrix9 Inverse(const Matrix9*);

	float Determinant(const Matrix9*);
}

#endif