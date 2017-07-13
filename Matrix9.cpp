#include "Matrix9.h"

CoreMatrix9::Matrix9::Matrix9() 
{
	this->m[0][0] = 0;
	this->m[0][1] = 0;
	this->m[0][2] = 0;
	this->m[1][0] = 0;
	this->m[1][1] = 0;
	this->m[1][2] = 0;
	this->m[2][0] = 0;
	this->m[2][1] = 0;
	this->m[2][2] = 0;
}

CoreMatrix9::Matrix9::Matrix9(const float M0, const float M1, const float M2, const float M3, const float M4, const float M5, const float M6, const float M7, const float M8)
{
	this->m[0][0] = M0;
	this->m[0][1] = M1;
	this->m[0][2] = M2;
	this->m[1][0] = M3;
	this->m[1][1] = M4;
	this->m[1][2] = M5;
	this->m[2][0] = M6;
	this->m[2][1] = M7;
	this->m[2][2] = M8;
}

CoreMatrix9::Matrix9::Matrix9(const float M[9]) 
{
	this->m[0][0] = M[0];
	this->m[0][1] = M[1];
	this->m[0][2] = M[2];
	this->m[1][0] = M[3];
	this->m[1][1] = M[4];
	this->m[1][2] = M[5];
	this->m[2][0] = M[6];
	this->m[2][1] = M[7];
	this->m[2][2] = M[8];
}

CoreMatrix9::Matrix9 CoreMatrix9::Matrix9::NMatrix9()
{
	return *new Matrix9();
}

CoreMatrix9::Matrix9::Matrix9(const Matrix9* a)
{
	this->m[0][0] = a->m[0][0];
	this->m[0][1] = a->m[0][1];
	this->m[0][2] = a->m[0][2];
	this->m[1][0] = a->m[1][0];
	this->m[1][1] = a->m[1][1];
	this->m[1][2] = a->m[1][2];
	this->m[2][0] = a->m[2][0];
	this->m[2][1] = a->m[2][1];
	this->m[2][2] = a->m[2][2];
}

void CoreMatrix9::Matrix9::DMatrix9()
{
	delete(this);
}

CoreMatrix9::Matrix9 CoreMatrix9::Transpose(const Matrix9* a)
{
	return Matrix9(a->m[0][0], a->m[1][0], a->m[2][0], a->m[0][1], a->m[1][1], a->m[2][1], a->m[0][2], a->m[1][2], a->m[2][2]);
}

CoreMatrix9::Matrix9 CoreMatrix9::Inverse(const Matrix9* a)
{
	Matrix9 Result(a->m[1][1] * a->m[2][2] - a->m[1][2] * a->m[2][1], -(a->m[1][0] * a->m[2][2] - a->m[1][2] * a->m[2][0]), a->m[1][0] * a->m[2][1] - a->m[1][1] * a->m[2][0], -(a->m[0][1] * a->m[2][2] - a->m[0][2] * a->m[2][1]), a->m[0][0] * a->m[2][2] - a->m[0][2] * a->m[2][0], -(a->m[0][0] * a->m[2][1] - a->m[0][1] * a->m[2][0]), a->m[0][1] * a->m[1][2] - a->m[0][2] * a->m[1][1], -(a->m[0][0] * a->m[1][2] - a->m[0][2] * a->m[1][0]), a->m[0][0] * a->m[1][1] - a->m[0][1] * a->m[1][0]);
	Result = Transpose(&Result);
	float Det = Determinant(&Result);
	return Result / Det;
}

float CoreMatrix9::Determinant(const Matrix9* a)
{
	return a->m[0][0] * (a->m[1][1] * a->m[2][2] - a->m[1][2] * a->m[2][1]) - a->m[0][1] * (a->m[1][0] * a->m[2][2] - a->m[1][2] * a->m[2][0]) + a->m[0][2] * (a->m[1][0] * a->m[2][1] - a->m[1][1] * a->m[2][0]);
}